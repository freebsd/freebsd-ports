PORTNAME=	gnome_subr
PORTVERSION=	1.0
CATEGORIES=	sysutils
DISTFILES=	# none

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Common startup and shutdown subroutines used by GNOME scripts

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${PORTSDIR}/COPYRIGHT

NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	etc/gnome.subr

do-install:
	${INSTALL_DATA} ${FILESDIR}/gnome.subr ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
