# ex:ts=8
# Ports collection makefile for:	Movable Type Plugin Manager
# Date created:			Nov 21, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MT-PM
PORTVERSION=	0.1.8
CATEGORIES=	www
MASTER_SITES=	http://manager.mt-plugins.org/ \
  		http://mt-plugins.org/
DISTFILES=	PluginManager-${PORTVERSION}${EXTRACT_SUFX} \
		archives.xml
EXTRACT_ONLY=	PluginManager-${PORTVERSION}${EXTRACT_SUFX}
IGNOREFILES=	archives.xml

MAINTAINER=	rayners@rayners.org
COMMENT=	Movable Type Plugin Manager

RUN_DEPENDS=	${CGIDIR}/mt.cgi:${PORTSDIR}/www/MT \
  		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5_RUN=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/www/data/mt
CGIDIR=		${PREFIX}/www/cgi-bin/mt

PLIST_SUB+=	DATADIR="${DATADIR:S,^${PREFIX}/,,}" \
  		CGIDIR="${CGIDIR:S,^${PREFIX}/,,}"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mt-pm.cgi ${CGIDIR}
	@${MKDIR} ${CGIDIR}/extlib/MT/Plugins
	${INSTALL_DATA} ${WRKSRC}/Manager.pm ${CGIDIR}/extlib/MT/Plugins
	@${MKDIR} ${CGIDIR}/tmpl/plugins
	${INSTALL_DATA} ${WRKSRC}/tmpl/*.tmpl ${CGIDIR}/tmpl/plugins
	${INSTALL_DATA} ${WRKSRC}/tmpl/styles-pm.css ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tmpl/dot.gif ${DATADIR}/images

post-install:
	${INSTALL_DATA} ${DISTDIR}/archives.xml ${CGIDIR}/plugins/plugins.xml
	@${MKDIR} ${CGIDIR}/plugins/docs ${CGIDIR}/plugins/manager-cache
	@${CHOWN} -R www:www ${CGIDIR}/mt-pm.cgi \
		${CGIDIR}/extlib/MT/Plugins/Manager.pm \
		${CGIDIR}/tmpl/plugins \
		${DATADIR}/styles-pm.css \
		${DATADIR}/images/dot.gif \
		${CGIDIR}/plugins/plugins.xml \
		${CGIDIR}/plugins/docs \
		${CGIDIR}/plugins/manager-cache

.include <bsd.port.mk>
