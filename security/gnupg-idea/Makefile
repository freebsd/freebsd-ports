# New ports collection makefile for:	gnupg-rsa
# Date created:		10 May, 2000 
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnupg-rsa
PORTVERSION=	1.0.1
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.gnupg.org/pub/gcrypt/contrib/

MAINTAINER=	dirk.meyer@dinoex.sub.org

RESTRICTED=	"Crypto; export-controlled"
RUN_DEPENDS=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg
NO_WRKSUBDIR=	yes
DIST_SUBDIR=    ${PORTNAME}
CFLAGS+=	-O2 -shared -fPIC -DIS_MODULE
CFLAGS+=	-Wall -Wcast-align -Wshadow -Wstrict-prototypes

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must set variable USA_RESIDENT to YES, if you are USA resident
	@${ECHO_MSG} or to NO, if you aren\'t USA resident to build this package
	@${FALSE}
.endif

.if ${USA_RESIDENT} == NO
DISTFILES=	rsa.c idea.c
CONTRIB=	rsa idea
#EXTRACT_ONLY=
.else
do-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} rsaref not yet supported
	@${FALSE}
.endif

.include <bsd.port.pre.mk>

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.for i in ${DISTFILES}
	${CP} ${_DISTDIR}/${i} ${WRKSRC}/${i}
.endfor

do-build:
.for i in ${CONTRIB}
	${CC} ${CFLAGS} -o ${WRKSRC}/${i} ${WRKSRC}/${i}.c
.endfor

do-install:
.for i in ${CONTRIB}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/lib/gnupg/${i}
.endfor

.include <bsd.port.post.mk>
