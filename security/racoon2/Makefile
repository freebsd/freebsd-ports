# New ports collection makefile for:	racoon2
# Date created:		4 Feb 2005
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	racoon2
PORTVERSION=	20050128b
CATEGORIES=	security net ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/racoon2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Racoon2 IPsec daemon

USE_RC_SUBR=	YES
USE_OPENSSL=	YES

USE_AUTOCONF_VER=259
CONFIGURE_TARGET=
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${LOCALBASE}/etc

.if !defined(NOPORTDOCS)
PORTDOCS=	INSTALL USAGE.iked USAGE.kinkd USAGE.spmd config-usage.ja.txt
PORTDOCS+=	draft-ietf-ipsec-ikev2-17.txt draft-ietf-kink-kink-06.txt
PORTDOCS+=	iked-memo.ja.txt kink-spec-supplement.ja.txt
PORTDOCS+=	kinkd-data-struct.obj kinkd-impl.ja.txt kinkd-install.ja.txt
PORTDOCS+=	kinkd-state-txn.obj libracoon.ja.txt specification.ja.txt
PORTDOCS+=	spmif.txt system-message.ja.txt
.endif

pre-patch:
	(cd ${WRKSRC}/samples ;\
	${MV} racoon2.conf racoon2.conf.in ;\
	${MV} init.d-kinkd init.d-kinkd.in ;\
	${MV} init.d-spmd init.d-spmd.in ;\
	${MV} rc.d-kinkd rc.d-kinkd.in ;\
	${MV} rc.d-spmd rc.d-spmd.in )

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.jp ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.iked ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif
	@if [ -z `/sbin/sysctl -a | ${GREP} -q ipsec && echo ipsec` ]; then \
	    ${ECHO_MSG} "WARNING: IPsec feature is disabled on this host"; \
	    ${ECHO_MSG} "         You must build the kernel if you want to run racoon on the host"; \
	fi ;

.include <bsd.port.mk>
