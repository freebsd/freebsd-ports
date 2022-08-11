PORTNAME=	s6-rc
PORTVERSION=	0.5.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Skarnet.org service manager

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	execline>=2.9.0.0:lang/execline \
		skalibs>=2.12.0.0:devel/skalibs \
		s6>=2.11.1.0:sysutils/s6
RUN_DEPENDS=	execline>=2.9.0.0:lang/execline \
		skalibs>=2.12.0.0:devel/skalibs \
		s6>=2.11.1.0:sysutils/s6
LIB_DEPENDS=	libs6.so:sysutils/s6 \
		libskarnet.so:devel/skalibs

USES=		gmake

USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

FLAVORS=	hier run
FLAVOR?=	${FLAVORS:[1]}
run_PKGNAMESUFFIX= -run

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
.endif
LIVEDIR?=	/var/run/${PORTNAME}

CONFIGURE_ARGS+=--prefix=${PREFIX} \
	--with-include=${LOCALBASE}/include \
	--with-lib=${LOCALBASE}/lib/skalibs \
	--with-lib=${LOCALBASE}/lib/execline \
	--with-lib=${LOCALBASE}/lib/s6 \
	--with-dynlib=${LOCALBASE}/lib \
	--livedir=${LIVEDIR} \
	--enable-shared

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
.for d in bin libexec
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${d}/*
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libs6rc.so.${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
