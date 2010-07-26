# New ports collection makefile for:	racoon2
# Date created:		4 Feb 2005
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	racoon2
PORTVERSION=	20100526a
CATEGORIES=	security net ipv6
MASTER_SITES=	ftp://ftp.racoon2.wide.ad.jp/pub/racoon2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

USE_RC_SUBR=	YES
USE_OPENSSL=	YES

USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/racoon2

OPTIONS=	KINK "enable KINK support" off

.include <bsd.port.pre.mk>

pre-configure:
.if defined (WITH_KINK)
.if !exists(/usr/lib/libkrb5.a)
	@${ECHO_MSG} 'Required Kerberos5 is not in this system.  Disable KINK support.'
CONFIGURE_ARGS+=	--disable-kinkd
PLIST_SUB+=	KINK="@comment "
.else
CONFIGURE_ARGS+=	--enable-kinkd
MAKE_ENV=	WITH_KINK=yes
MAN8+=		kinkd.8
PLIST_SUB+=	KINK=""
.endif
.else
CONFIGURE_ARGS+=	--disable-kinkd
PLIST_SUB+=	KINK="@comment "
.endif

.if !defined(NOPORTDOCS)
PORTDOCS+=	INSTALL USAGE config-usage.ja.txt config-usage.txt
PORTDOCS+=	iked-memo.ja.txt libracoon.ja.txt specification.ja.txt
PORTDOCS+=	spmif.txt style.txt system-message.ja.txt
.if defined (WITH_KINK)
PORTDOCS+=	kinkd-data-struct.obj kinkd-impl.ja.txt
PORTDOCS+=	kinkd-install.ja.txt kinkd-state-txn.obj
.endif
.endif

MAN8+=		spmd.8 spmdctl.8 pskgen.8 iked.8

post-patch:
.if !defined(NOPORTDOCS)
.for FILE in ${PORTDOCS}
	@${REINPLACE_CMD} -e 's|/usr/local/racoon2|${LOCALBASE}|' ${WRKSRC}/doc/${FILE}
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.jp ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif
	@if [ -z `/sbin/sysctl -a | ${GREP} -q ipsec && echo ipsec` ]; then \
	    ${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	    ${ECHO_MSG} "         You must build the kernel if you want to run racoon on the host"; \
	fi ;

.include <bsd.port.post.mk>
