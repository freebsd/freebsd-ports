# New ports collection makefile for:	quickie
# Date Created:				2006-05-16
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	quickie
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/

MAINTAINER=	shaun@inerd.com
COMMENT=	A small footprint, fast Wiki engine written in C++

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}		\
		--sysconfdir=${PREFIX}/etc	\
		--localstatedir=${DATADIR}

MAN1=		quickie-config.1 quickie_prime.1 quickie.1 quickie_svt.1 \
		quickie_license.1 quickie_post_install.1

SUB_FILES=	pkg-message

WWWOWN?=	www
WWWGRP?=	www
WWWDIR?=	${PREFIX}/www

PORTDOCS=	${DISTNAME}.pdf

.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 500041)
BROKEN=		does not compile on 4.x; needs a newer libc
.endif

post-patch:
	@${CP} ${FILESDIR}/freebsd.h ${WRKSRC}/lib
	@${REINPLACE_CMD} -e 's#var/[^ ]*\.man##g' ${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${DATADIR}/admin
	@${MKDIR} ${DATADIR}/manual

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
.if !defined(WITHOUT_CGICOPY)
	@if [ -d ${WWWDIR}/cgi-bin/ ]; then \
	    if [ ! -f ${WWWDIR}/cgi-bin/${PORTNAME} ]; then \
	        ${ECHO_MSG} "===> Copying CGI binary..." ; \
	        ${CP} -p ${PREFIX}/bin/${PORTNAME} ${WWWDIR}/cgi-bin/${PORTNAME} ; \
	        ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/cgi-bin/${PORTNAME} ; \
	    fi ; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
