PORTNAME=	cfs
DISTVERSION=	1.5.0.beta
CATEGORIES=	security
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Cryptographic file system implemented as a user-space NFS server

ALL_TARGET=	cfs
MAKE_ARGS=	CC="${CC}"

CFSD_BOOTSTRAP=	${PREFIX}/cfsd-bootstrap
USE_RC_SUBR=	cfsd
SUB_FILES=	pkg-message
SUB_LIST=	CFSD_BOOTSTRAP=${CFSD_BOOTSTRAP}
PLIST_SUB=	CFSD_BOOTSTRAP=${CFSD_BOOTSTRAP}

post-patch:
	${REINPLACE_CMD} 's/^\.TH SSH/.TH CFSSH/' ${WRKSRC}/cfssh.1

do-install:
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} ccat cfsd cname ${STAGEDIR}${PREFIX}/sbin; \
	    ${INSTALL_PROGRAM} cattach cdetach cmkdir cpasswd ${STAGEDIR}${PREFIX}/bin; \
	    ${INSTALL_SCRIPT} cfssh ${STAGEDIR}${PREFIX}/bin/cfssh; \
	    ${INSTALL_MAN} cattach.1 cdetach.1 cmkdir.1 cpasswd.1 cfssh.1 ${STAGEDIR}${PREFIX}/man/man1; \
	    ${INSTALL_MAN} ccat.8 cfsd.8 cname.8 ${STAGEDIR}${PREFIX}/man/man8; \
	    ${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/cfs; \
	    ${INSTALL_DATA} README.install notes.ms ${STAGEDIR}${PREFIX}/share/doc/cfs
	${INSTALL} -d -m 0 ${STAGEDIR}${CFSD_BOOTSTRAP}

.include <bsd.port.mk>
