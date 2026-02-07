PORTNAME=	doas
PORTVERSION=	6.3p13
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/thejessesmith/doas/archive/${PORTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Simple sudo alternative to run commands as another user
WWW=		https://codeberg.org/thejessesmith/doas/

LICENSE=	BSD2CLAUSE ISCL
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_ISCL=		${WRKSRC}/LICENSE

USES=		cpe gmake
CPE_VENDOR=	doas_project
CPE_VERSION=	${PORTVERSION:C/p.+//}
CPE_UPDATE=	${PORTVERSION:C/[^p]*//}

MAKE_ENV+=	TARGETPATH=-DGLOBAL_PATH='\"${_GLOBAL_PATH}\"'

CONFLICTS=	opendoas

BINMODE=	4755
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/doas \
		bin/doasedit \
		bin/vidoas \
		etc/doas.conf.sample \
		share/man/man1/doas.1.gz \
		share/man/man5/doas.conf.5.gz \
		share/man/man8/doasedit.8.gz \
		share/man/man8/vidoas.8.gz

# These are upstream's default paths that are set for the GLOBAL_PATH variable
# in doas.h since the 6.1 release. Those paths are then used for target user's
# PATH variable instead of those of the original user.
_GLOBAL_PATH?=	${LOCALBASE}/sbin:${LOCALBASE}/bin:/usr/sbin:/usr/bin:/sbin:/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vidoas.final ${STAGEDIR}${PREFIX}/bin/vidoas
	${INSTALL_SCRIPT} ${WRKSRC}/doasedit ${STAGEDIR}${PREFIX}/bin/doasedit
	${INSTALL_MAN} ${WRKSRC}/doas.1.final ${STAGEDIR}${PREFIX}/share/man/man1/doas.1
	${INSTALL_MAN} ${WRKSRC}/doas.conf.5.final ${STAGEDIR}${PREFIX}/share/man/man5/doas.conf.5
	${INSTALL_MAN} ${WRKSRC}/vidoas.8.final ${STAGEDIR}${PREFIX}/share/man/man8/vidoas.8
	${INSTALL_MAN} ${WRKSRC}/doasedit.8 ${STAGEDIR}${PREFIX}/share/man/man8/doasedit.8
	${INSTALL_DATA} ${WRKSRC}/doas.conf.sample ${STAGEDIR}${PREFIX}/etc/doas.conf.sample

.include <bsd.port.mk>
