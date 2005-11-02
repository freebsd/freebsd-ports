# New ports collection makefile for:	racoon2
# Date created:		4 Feb 2005
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	racoon2
PORTVERSION=	20051102a
CATEGORIES=	security net ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/racoon2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

.if !exists(/usr/lib/libkrb5.a)
BROKEN=		"Kerberos5 is required in the system"
.endif

USE_RC_SUBR=	YES
USE_OPENSSL=	YES

USE_AUTOCONF_VER=259
CONFIGURE_TARGET=
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${LOCALBASE}/etc
USE_REINPLACE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	INSTALL USAGE USAGE.iked USAGE.kinkd USAGE.spmd
PORTDOCS+=	config-usage.ja.txt config-usage.txt
PORTDOCS+=	iked-memo.ja.txt kinkd-data-struct.obj kinkd-impl.ja.txt
PORTDOCS+=	kinkd-install.ja.txt kinkd-state-txn.obj libracoon.ja.txt
PORTDOCS+=	specification.ja.txt spmif.txt style.txt system-message.ja.txt
.endif

MAN8=		spmd.8 spmdctl.8 kinkd.8

post-patch:
.if !defined(NOPORTDOCS)
.for FILE in ${PORTDOCS}
	${REINPLACE_CMD} -e 's|/usr/local/racoon2|${LOCALBASE}|' ${WRKSRC}/doc/${FILE}
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

.include <bsd.port.mk>
