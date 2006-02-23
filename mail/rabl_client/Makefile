# New ports collection makefile for:	rabl_client
# Date created:				2005-10-07
# Whom:					Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	rabl_client
PORTVERSION=	1.0.0
CATEGORIES=	mail dns
MASTER_SITES=	http://www.nuclearelephant.com/projects/rabl/sources/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Reactive Autonomous Blackhole List client

GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_ENV=		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--localstatedir=${VAR_DIR}

VAR_DIR?=	/var/spool/${PORTNAME}

PORTDOCS=	CHANGE README RELEASE.NOTES

OPTIONS=	DEBUG "Enable DEBUG messages"	off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-g -DDEBUG
STRIP_CMD=		# empty
.endif

post-install:
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0640 \
		${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 0640 \
		${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
