# $FreeBSD$

PORTNAME=	doas
PORTVERSION=	6.2
CATEGORIES=	security

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Simple sudo alternative to run commands as another user

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_ISCL=		${WRKSRC}/LICENSE

USES=	gmake
USE_GITHUB=	yes
GH_ACCOUNT=	slicer69

MAKE_ENV+=	TARGETPATH=-DGLOBAL_PATH='\"${_GLOBAL_PATH}\"'

BINMODE=	4755

SUB_FILES=	pkg-message
PLIST_FILES=	bin/doas \
		man/man5/doas.conf.5.gz \
		man/man1/doas.1.gz

# These are upstream's default paths that are set for the GLOBAL_PATH variable
# in doas.h since the 6.1 release. Those paths are then used for target user's
# PATH variable instead of those of the original user.
#
# See also:
#  * https://github.com/slicer69/doas/blob/6.1/doas.h#L36
#  * https://github.com/slicer69/doas/releases/tag/6.1
_GLOBAL_PATH?=	${LOCALBASE}/sbin:${LOCALBASE}/bin:/usr/sbin:/usr/bin:/sbin:/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doas.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doas.conf.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
