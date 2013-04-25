# $FreeBSD$

PORTNAME=	gnupg-idea
PORTVERSION=	1.0.6
PORTREVISION=	4
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

RUN_DEPENDS=	${LOCALBASE}/bin/gpgv:${PORTSDIR}/security/gnupg1

EXTRACT_AFTER_ARGS=	> ${WRKSRC}/idea.c

NO_WRKSUBDIR=	yes
CFLAGS+=	-shared -fPIC -DIS_MODULE
CFLAGS+=	-Wall -Wcast-align -Wshadow -Wstrict-prototypes
PLIST=		${WRKDIR}/.PLIST.more

OPTIONS_DEFINE=	IDEA
OPTIONS_DEFINE=	IDEA
OPTIONS_DEFAULT=IDEA
IDEA_DESC=	IDEA encyrption

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDEA}
CONTRIB=	idea rsa
DISTFILES=	idea.c.gz:idea rsa.c
EXTRACT_ONLY=	idea.c.gz
.else
CONTRIB=	rsa
DISTFILES=	rsa.c
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

.include <bsd.port.mk>
