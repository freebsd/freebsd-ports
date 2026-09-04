PORTNAME=	nuget2tuple
PORTVERSION=	1.0.0
CATEGORIES=	ports-mgmt

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Generate NUGET_NUPKGS knob for .NET ports
WWW=		https://github.com/freebsd/freebsd-ports

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	dotnet:lang/dotnet

NO_ARCH=	yes
NO_BUILD=	yes
DISTFILES=	# none

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME}.in ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
