# New ports collection makefile for:	gnupg-idea
# Date created:		10 May, 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnupg-idea
PORTVERSION=	1.0.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG} \
		ftp://ftp.gnupg.org/gcrypt/%SUBDIR%/ \
		http://www.gnupg.dk/contrib-dk/:idea \
		http://www.gnupg.cz/~rp/GnuPG/extensions/:idea \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/gnupg/&,}
MASTER_SITE_SUBDIR=	contrib
DISTFILES=	# later
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	# none

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	IDEA extension module for gnupg (and RSA for demonstration)

RUN_DEPENDS=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg

EXTRACT_AFTER_ARGS=	> ${WRKSRC}/idea.c
RESTRICTED=	"IDEA is Patented in the USA and many European countries"
NO_PACKAGE=	${RESTRICTED}

NO_WRKSUBDIR=	yes
CFLAGS+=	-shared -fPIC -DIS_MODULE
CFLAGS+=	-Wall -Wcast-align -Wshadow -Wstrict-prototypes
PLIST=		${WRKDIR}/.PLIST.more

.include <bsd.port.pre.mk>

.if defined(MAKE_IDEA) && !defined(WITHOUT_IDEA)
CONTRIB=	idea rsa
DISTFILES=	idea.c.gz:idea rsa.c
EXTRACT_ONLY=	idea.c.gz
.else
CONTRIB=	rsa
DISTFILES=	rsa.c

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must set variable MAKE_IDEA to YES, only rsa is build now.
.endif

pre-extract:
	@${SED} -e s!%%PREFIX%%!${PREFIX}!g ${PKGMESSAGE}

post-extract:
.for i in rsa.c
	@${TR} -d '\r' <${_DISTDIR}/${i} >${WRKSRC}/${i}
.endfor

do-patch:
.for i in ${CONTRIB}
	@${ECHO_MSG} "===>  Applying extra patch ${i}.c"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/patch-${i}.c
.endfor

do-build:
.for i in ${CONTRIB}
	${CC} ${CFLAGS} -o ${WRKSRC}/${i} ${WRKSRC}/${i}.c
	${ECHO_CMD} "lib/gnupg/${i}" >>${PLIST}
.endfor
	${ECHO_CMD} "@dirrm lib/gnupg" >>${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/gnupg
.for i in ${CONTRIB}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/lib/gnupg/${i}
.endfor

.include <bsd.port.post.mk>
