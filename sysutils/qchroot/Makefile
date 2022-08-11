PORTNAME=	qchroot
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	qchroot1@a1poweruser.com
COMMENT=	Utility for deployment of chroot environments

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qchroot		\
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/qchroot.bootime	\
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN}    ${WRKSRC}/qchroot.8		\
		${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
