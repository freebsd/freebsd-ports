# New ports collection makefile for:	quickie
# Date Created:				2006-05-16
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	quickie
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	A small footprint, fast Wiki engine written in C++

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}		\
		--sysconfdir=${PREFIX}/etc	\
		--localstatedir=${DATADIR}

MAN1=		quickie-config.1 quickie_prime.1 quickie.1 quickie_svt.1 \
		quickie_license.1 quickie_post_install.1

SUB_FILES=	pkg-message

PORTDOCS=	${DISTNAME}.pdf

.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${CP} ${FILESDIR}/freebsd.h ${WRKSRC}/lib
	@${REINPLACE_CMD} -e 's|output_html_quote::name()|name()|' \
		${WRKSRC}/lib/output/html_quote.h
	@${REINPLACE_CMD} -e 's|input_uudecode::read_inner|read_inner|' \
		${WRKSRC}/lib/input/uudecode.h

pre-install:
	@${MKDIR} ${DATADIR}/admin
	@${MKDIR} ${DATADIR}/manual

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
.if !defined(WITHOUT_CGICOPY)
	@if [ -d ${PREFIX}/www/cgi-bin/ ]; then \
	    if [ ! -f ${PREFIX}/www/cgi-bin/${PORTNAME} ]; then \
	        ${ECHO_MSG} "===> Copying CGI binary..." ; \
	        ${CP} -p ${PREFIX}/bin/${PORTNAME} ${PREFIX}/www/cgi-bin/${PORTNAME} ; \
	        ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/www/cgi-bin/${PORTNAME} ; \
	    fi ; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
