# New ports collection makefile for:    milter-sender
# Date created:                         7 Sep 2003
# Whom:                                 Andrey Chernov
#
# $FreeBSD$
#

PORTNAME=	milter-sender
PORTVERSION=	0.62
CATEGORIES=	mail
MASTER_SITES=	http://www.snert.com/Software/download/
DISTFILES=	libsnert-1.40.tgz milter-sender-${PORTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time sender address verification, based on Milter API

RESTRICTED=	No redistribution allowed

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/com/snert/src/milter-sender
MAKEFILE=	makefile

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 440000 )
BUILD_DEPENDS+=	gxargs:${PORTSBASE}/misc/findutils
.endif

.if !exists(/usr/lib/libmilter.a) && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12
.endif
.if exists(${LOCALBASE}/lib/libmilter.a)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

DOCS=		CHANGES.TXT index.shtml style.css mailto.js \
		LICENSE.TXT

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-db --localstatedir=/var/spool --enable-cache=flatfile \
		--enable-milter-cf="${PREFIX}/etc/milter-sender.cf"
.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} NAME=milter_sender

post-extract:
	${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/milter-sender.sh > ${WRKSRC}/milter-sender.sh.freebsd

post-patch:
.if ( ${OSVERSION} < 440000 ) # please contact vs@ if in doubt
	${REINPLACE_CMD} 's/xargs -J{}/gxargs -i{}/' ${WRKSRC}/../lib/configure
.endif
	${REINPLACE_CMD} "s,-fvolatile,," ${WRKSRC}/configure

pre-configure:
	@cd ${WRKSRC}/../lib && \
	${SETENV} CC="${CC}" CXX="${CXX}" \
	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	INSTALL_DATA="${INSTALL_DATA}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	@cd ${WRKSRC}/../lib && \
	${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/Img
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@cd ${WRKSRC}/Img && \
	${INSTALL_DATA} *.gif *.png ${DOCSDIR}/Img
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
