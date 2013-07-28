# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	quickie
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY:=	${DISTFILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small footprint, fast Wiki engine written in C++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}/etc \
		--localstatedir=${DATADIR}
USE_PERL5_BUILD=	yes

SUB_FILES=	pkg-message

MAN1=		quickie-config.1 quickie_prime.1 quickie.1 quickie_svt.1 \
		quickie_license.1 quickie_post_install.1
PORTDOCS=	${DISTNAME}.pdf

OPTIONS_DEFINE=	CGI DOCS
CGI_DESC=	Install CGI binary

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DISTNAME}.pdf
.endif

post-patch:
	@${CP} ${FILESDIR}/freebsd.h ${WRKSRC}/lib
	@${REINPLACE_CMD} -e 's|output_html_quote::name()|name()|' \
		${WRKSRC}/lib/output/html_quote.h
	@${REINPLACE_CMD} -e 's|input_uudecode::read_inner|read_inner|' \
		${WRKSRC}/lib/input/uudecode.h
# Fix -jX builds: tell compiler to generate files in the right place
	@${PERL} -0pi -e 's/(\$$\(CXX\).*?\s+-c\s+.*?) \
		\s+mv\s+\S+/$$1 -o/sgx' ${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${DATADIR}/admin ${DATADIR}/manual

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
.if ${PORT_OPTIONS:MCGI}
	@if [ -d ${PREFIX}/www/cgi-bin ]; then \
	    if [ ! -f ${PREFIX}/www/cgi-bin/${PORTNAME} ]; then \
	        ${ECHO_MSG} "===> Copying CGI binary..." ; \
	        ${CP} -p ${PREFIX}/bin/${PORTNAME} ${PREFIX}/www/cgi-bin/${PORTNAME} ; \
	        ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/www/cgi-bin/${PORTNAME} ; \
	    fi ; \
	fi
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
