# New ports collection makefile for:	foswiki
# Date created:		2009-04-13
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	foswiki
PORTVERSION=	1.0.6
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	Foswiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A free and open source enterprise wiki

BUILD_DEPENDS=	p5-CGI.pm>3.37:${PORTSDIR}/www/p5-CGI.pm \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-File-Path>=0:${PORTSDIR}/devel/p5-File-Path \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-IO>=1.22:${PORTSDIR}/devel/p5-IO \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	5.8.4+
USE_APACHE=	2.0+
NO_BUILD=	yes

OPTIONS=	OPTINT "Install Perl modules for intl character support" Off \
		OPTOTH "Install other optional Perl modules" On \
		APACHE "Install sample Apache 2.x config file" Off

.include <bsd.port.pre.mk>
.if defined(WITH_OPTINT)
BUILD_DEPENDS+=	p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-Encode-compat>=0:${PORTSDIR}/converters/p5-Encode-compat \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Unicode-MapUTF8>=0:${PORTSDIR}/converters/p5-Unicode-MapUTF8
RUN_DEPENDS+=	p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-Encode-compat>=0:${PORTSDIR}/converters/p5-Encode-compat \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Unicode-MapUTF8>=0:${PORTSDIR}/converters/p5-Unicode-MapUTF8
.endif

.if defined(WITH_OPTOTH)
BUILD_DEPENDS+=	p5-Apache-Htpasswd>=0:${PORTSDIR}/security/p5-Apache-Htpasswd \
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-CGI-Session>=4.30:${PORTSDIR}/www/p5-CGI-Session \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Lingua-EN-Sentence>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Sentence \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Net>=1.19:${PORTSDIR}/net/p5-Net
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif

.if defined(WITH_APACHE)
PLIST_SUB+=	NOAPACHE="" CONFDIR=${CONFDIR_REL}
CONFDIR=	${PREFIX}/${CONFDIR_REL}
CONFDIR_REL=	${APACHEETCDIR}/Includes

PKGMESSAGE=	pkg-message-apache
SUB_FILES+=	pkg-message-apache
.else
PLIST_SUB+=	NOAPACHE="@comment "
PKGMESSAGE=	pkg-message-noapache
SUB_FILES+=	pkg-message-noapache
.endif

SUB_FILES+=	LocalSite.cfg

post-patch:
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

post-install:
.if defined(WITH_APACHE)
	@if [ -d "${CONFDIR}" ]; then \
	  ${INSTALL_DATA} ${WRKSRC}/foswiki_httpd_conf.txt \
		${CONFDIR}/foswiki.conf.sample; \
	else \
	  ${ECHO_MSG} "" ; \
	  ${ECHO_MSG} "Please check your Apache 2.x installation -" ; \
	  ${ECHO_MSG} "${CONFDIR} doesn't exist," ; \
	  ${ECHO_MSG} "so I cannot install foswiki.conf.sample there!" ; \
	  ${ECHO_MSG} "" ; \
	  ${FALSE} ; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/bsd.foswiki.mk"
.include <bsd.port.post.mk>
