# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	tinyca
PORTVERSION=	0.7.5
PORTREVISION=	5
CATEGORIES=	security net
MASTER_SITES=	http://tinyca.sm-zone.net/ \
		http://tinyca.sm-zone.net/old/
DISTNAME=	${PORTNAME}2-${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Simple graphical interface to manage a small Certification Authority

RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		zip:${PORTSDIR}/archivers/zip \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64

USE_BZIP2=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
NO_BUILD=	yes
DOC_FILES=	INSTALL
LIB_FILES=	CA.pm CERT.pm GUI.pm HELPERS.pm KEY.pm OpenSSL.pm REQ.pm TCONFIG.pm
LIB2_FILES=	CALLBACK.pm HELPERS.pm TCONFIG.pm WORDS.pm X509_browser.pm X509_infobox.pm

do-install:
	@${MKDIR} ${SITE_PERL}/${PORTNAME}/
	@${MKDIR} ${SITE_PERL}/${PORTNAME}/GUI
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/${file} ${SITE_PERL}/${PORTNAME}
.endfor
.for file in ${LIB2_FILES}
	@${INSTALL_DATA} ${WRKSRC}/lib/GUI/${file} ${SITE_PERL}/${PORTNAME}/GUI
.endfor
	@${INSTALL_DATA} ${WRKSRC}/templates/openssl.cnf ${PREFIX}/etc/tinyca.cnf.sample
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		-e "s:%%SITE_PERL%%:${SITE_PERL}:g" \
		-e "s:%%OPENSSLBASE%%:${OPENSSLBASE}:g" \
		${WRKSRC}/tinyca2 >${WRKSRC}/tinyca.new
	@${INSTALL_SCRIPT} ${WRKSRC}/tinyca.new ${PREFIX}/bin/tinyca

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
