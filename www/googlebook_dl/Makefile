# $FreeBSD$

PORTNAME=	googlebook_dl
PORTVERSION=	20150711
CATEGORIES=	www
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Command-line utility for downloading books from Google Books

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	wget:ftp/wget

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
