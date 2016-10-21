# $FreeBSD$

PORTNAME=	foswiki
PORTVERSION=	1.1.9
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	Foswiki-${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Free and open source enterprise wiki

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Error>=0.15:lang/p5-Error \
		p5-Algorithm-Diff>=1.1901:devel/p5-Algorithm-Diff \
		p5-Text-Diff>=0.35:textproc/p5-Text-Diff \
		p5-Sort-Maker>=0.06:devel/p5-Sort-Maker

USES=		cpe perl5 tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	OPTINT OPTOTH APACHE
OPTIONS_DEFAULT=	OPTINT OPTOTH
OPTIONS_SUB=	yes
OPTINT_DESC=	Perl modules for intl character support
OPTOTH_DESC=	Other optional Perl modules
APACHE_DESC=	Apache web server and sample config file

OPTINT_RUN_DEPENDS=	p5-Locale-Maketext-Lexicon>=0:devel/p5-Locale-Maketext-Lexicon
OPTOTH_RUN_DEPENDS=	p5-Apache-Htpasswd>=0:security/p5-Apache-Htpasswd \
		p5-Archive-Tar>=0:archivers/p5-Archive-Tar \
		p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-CGI-Session>=4.40:www/p5-CGI-Session \
		p5-CSS-Minifier-XS>=0:textproc/p5-CSS-Minifier-XS \
		p5-JavaScript-Minifier-XS>=0:textproc/p5-JavaScript-Minifier-XS \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Lingua-EN-Sentence>=0:textproc/p5-Lingua-EN-Sentence \
		p5-libwww>=0:www/p5-libwww \
		p5-HTML-Tree>=3.23:www/p5-HTML-Tree \
		p5-Net>=1.19:net/p5-Net
APACHE_USE=	APACHE_RUN=22+
APACHE_SUB_FILES=	pkg-message-apache
APACHE_SUB_LIST=	FOSCONFDIR=${CONFDIR}
APACHE_PLIST_SUB=	CONFDIR=${APACHEETCDIR}/Includes
APACHE_VARS=	PKGMESSAGE=pkg-message-apache \
		CONFDIR=${PREFIX}/${APACHEETCDIR}/Includes
APACHE_SUB_FILES_OFF=	pkg-message-noapache
APACHE_VARS_OFF=	PKGMESSAGE=pkg-message-noapache

SUB_FILES+=	LocalSite.cfg
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	@${RM} -r ${WRKSRC}/lib/CPAN
	@${MV} ${WRKSRC}/bin-htaccess.txt ${WRKSRC}/bin/.htaccess.txt
	@${CP} ${WRKSRC}/subdir-htaccess.txt ${WRKSRC}/working/.htaccess
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -i "" \
		-e "s|^#[[:space:]]*\(.*\)/home/httpd/foswiki|\1${WWWDIR}|g" \
		-e "s|^#[[:space:]]*\(.*\)\(\= \'/foswiki/\)|\1\2|g" \
		-e "s|/bin/grep|/usr/bin/grep|g" \
		lib/Foswiki.spec
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -i "" \
		-e "s|/var/www/foswiki|${WWWDIR}|g" \
		-e "s|192.168.1.10||g" \
		foswiki_httpd_conf.txt
	@cd ${WRKSRC}/bin && \
		${INSTALL_DATA} LocalLib.cfg.txt LocalLib.cfg && \
		${REINPLACE_CMD} -i "" -e "s|/absolute/path/to/your/lib|${WWWDIR}/lib|g" \
		LocalLib.cfg
	@${FIND} ${WRKSRC} -name \*.orig -delete

post-install-APACHE-on:
	@${MKDIR} ${STAGEDIR}${CONFDIR}
	@if [ -d "${STAGEDIR}${CONFDIR}" ]; then \
	  ${INSTALL_DATA} ${WRKSRC}/foswiki_httpd_conf.txt \
		${STAGEDIR}${CONFDIR}/foswiki.conf.sample; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install foswiki.conf.sample there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi

.include "${.CURDIR}/bsd.foswiki.mk"
.include <bsd.port.mk>
