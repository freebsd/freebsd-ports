PORTNAME=	s6-frontend
DISTVERSION=	0.0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Frontend to the s6 init system
WWW=		https://www.skarnet.org/software/s6-frontend/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	hier run
FLAVOR?=	${FLAVORS:[1]}
.if ${FLAVOR} == run # Follow hier(7)
BUILD_DEPENDS=	execline>=2.9.8.1:lang/execline \
		skalibs>=2.14.5.1:devel/skalibs \
		s6>=2.14.0.1:sysutils/s6 \
		s6-rc-run>=0.6.0.0:sysutils/s6-rc
RUN_DEPENDS=	execline>=2.9.8.1:lang/execline \
		skalibs>=2.14.5.1:devel/skalibs \
		s6>=2.14.0.1:sysutils/s6 \
		s6-rc-run>=0.6.0.0:sysutils/s6-rc
.else
BUILD_DEPENDS=	execline>=2.9.8.1:lang/execline \
		skalibs>=2.14.5.1:devel/skalibs \
		s6>=2.14.0.1:sysutils/s6 \
		s6-rc>=0.6.0.0:sysutils/s6-rc
RUN_DEPENDS=	execline>=2.9.8.1:lang/execline \
		skalibs>=2.14.5.1:devel/skalibs \
		s6>=2.14.0.1:sysutils/s6 \
		s6-rc>=0.6.0.0:sysutils/s6-rc
.endif
LIB_DEPENDS=	libs6.so:sysutils/s6 \
		libskarnet.so:devel/skalibs

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

run_PKGNAMESUFFIX=	-run

# The only difference between the hier and the run flavors is the default live directory path
# hard coded into the s6-rc utilities allowing their use without passing -l <live_dir>.
# A FreeBSD port should follow the operating system file system layout, but there is a corner
# case where s6-rc replacing base system init system *has* to deviate from hier(7).
# The problem is that s6-rc requires a writeable file system
# (to track service state, bind unix sockets, create named fifos)
# very early in the boot process before FreeBSD used to mount /var and /var/run.
# One way to satisfy this requirement is to mount a tmpfs directly under /.
# The live directory shouldn't be kept on /tmp because this often a small
# file system that could be exhausted by accident breaking s6-rc.
# Adding a small /run tmpfs dedicated to s6-rc solves this problem.
.if ${FLAVOR} == run # Follow hier(7)
LIVEDIR?=	/run/${PORTNAME}
SCANDIR?=	/run/service
STMPDIR?=	/run/s6-frontend
.endif
LIVEDIR?=	/var/run/${PORTNAME}
SCANDIR?=	/var/run/service
STMPDIR?=	/var/run/s6-frontend

CFLAGS+=	-D__BSD_VISIBLE

CONFIGURE_ARGS+=--prefix=${PREFIX} \
	--with-include=${LOCALBASE}/include \
	--with-lib=${LOCALBASE}/lib \
	--with-lib=${LOCALBASE}/lib/execline \
	--with-lib=${LOCALBASE}/lib/s6 \
	--with-dynlib=${LOCALBASE}/lib \
	--disable-s6li \
	--livedir=${LIVEDIR} \
	--scandir=${SCANDIR} \
	--enable-shared

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
