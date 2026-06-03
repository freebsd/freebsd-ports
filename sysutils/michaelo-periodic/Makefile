PORTNAME=		michaelo-periodic
PORTVERSION=	20260101
CATEGORIES=		sysutils

MAINTAINER=		michaelo@FreeBSD.org
COMMENT=		Scripts for the FreeBSD periodic(8) system from ${MAINTAINER}
WWW=			https://github.com/michael-o/freebsd-periodic

LICENSE=		APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=		yes
GH_ACCOUNT=		michael-o
GH_PROJECT=		freebsd-periodic

NO_ARCH=		yes
NO_BUILD=		yes
NO_TEST=		yes

PERIODIC_FILES=	etc/periodic/weekly/500.gitup \
				etc/periodic/weekly/550.make-src

PLIST_FILES=	${PERIODIC_FILES}

do-install:
.for _dir in ${PERIODIC_FILES:H:u}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${_dir}
.endfor
.for _file in ${PERIODIC_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${_file:C,^[^/]+/[^/]+/,,} ${STAGEDIR}${PREFIX}/${_file}
.endfor

.include <bsd.port.mk>
