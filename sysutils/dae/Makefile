PORTNAME=	dae
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	#empty
DISTFILES=	#none

MAINTAINER=	light@ether.org.za
COMMENT=	List and control system daemon

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/dae share/man/man1/dae.1.gz

do-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/dae.sh ${STAGEDIR}${PREFIX}/sbin/dae
	@${INSTALL_MAN} ${FILESDIR}/dae.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
