# New ports collection makefile for:	gnupg-idea
# Date created:		10 May, 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnupg-idea
PORTVERSION=	1.0.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/pub/gcrypt/%SUBDIR%/ \
		http://www.gnupg.dk/contrib-dk/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/gnupg/&,}
MASTER_SITE_SUBDIR=	contrib
DISTFILES=	${CONTRIB:S|$|.c|}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	# none

MAINTAINER=	dinoex@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg

RESTRICTED=	"IDEA is Patented in the USA and many European countries"

NO_WRKSUBDIR=	yes
CFLAGS+=	-shared -fPIC -DIS_MODULE
CFLAGS+=	-Wall -Wcast-align -Wshadow -Wstrict-prototypes
PLIST=		${WRKDIR}/.PLIST.more

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must set variable USA_RESIDENT to YES, if you are USA resident
	@${ECHO_MSG} or to NO, if you aren\'t USA resident to build this package
	@${FALSE}

.include <bsd.port.mk>

.elif defined(USA_RESIDENT)

.if ${USA_RESIDENT} == NO || defined(MAKE_IDEA)
CONTRIB=	idea rsa
.else
CONTRIB=	rsa

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must set variable MAKE_IDEA to YES, only rsa is build now.
.endif

.include <bsd.port.pre.mk>

pre-extract:
	@${SED} -e s!%%PREFIX%%!${PREFIX}!g ${PKGMESSAGE}

post-extract:
.for i in ${DISTFILES}
	@tr -d '\r' <${_DISTDIR}/${i} >${WRKSRC}/${i}
.endfor

do-patch:
.for i in ${CONTRIB}
	@${ECHO_MSG} "===>  Applying extra patch ${i}.c"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/patch-${i}.c
.endfor

do-build:
.for i in ${CONTRIB}
	${CC} ${CFLAGS} -o ${WRKSRC}/${i} ${WRKSRC}/${i}.c
	${ECHO} "lib/gnupg/${i}" >>${PLIST}
.endfor

do-install:
.for i in ${CONTRIB}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/lib/gnupg/${i}
.endfor

.include <bsd.port.post.mk>

.else

.endif
