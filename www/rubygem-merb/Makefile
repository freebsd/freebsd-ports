# Ports collection makefile for:	rubygem-merb
# Date created:				7 Oct 2008
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	merb
PORTVERSION=	0.9.3
CATEGORIES=	www rubygems
MASTER_SITES=	RF
DISTFILES=	${PORTNAME}-core-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-action-args-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-assets-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-gen-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-haml-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-builder-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-mailer-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-parts-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-cache-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-freezer-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-more-${PORTVERSION}${EXTRACT_SUFX} \
		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	clsung@freebsd.org
COMMENT=	An MVC web application framework in ruby

BUILD_DEPENDS=	rubygem-builder>=2.0.0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-erubis>0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-haml>=1.8.2:${PORTSDIR}/www/rubygem-haml \
		rubygem-hpricot>0:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-json_pure>0:${PORTSDIR}/devel/rubygem-json_pure \
		rubygem-mailfactory>=1.2.3:${PORTSDIR}/mail/rubygem-mailfactory \
		rubygem-mime-types>0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-mongrel>=1.0.1:${PORTSDIR}/www/rubygem-mongrel \
		rubygem-rack>0:${PORTSDIR}/www/rubygem-rack \
		rubygem-rspec>0:${PORTSDIR}/devel/rubygem-rspec \
		rubygem-ruby2ruby>=1.1.8:${PORTSDIR}/devel/rubygem-ruby2ruby
RUN_DEPENDS=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	rubygem-rubigen>0:${PORTSDIR}/devel/rubygem-rubigen

USE_RUBY=	yes
USE_RUBYGEMS=	yes

PLIST_SUB+=	GEM_LIB_DIR_CORE=${GEMS_DIR}/${PORTNAME}-core-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_CORE=${DOC_DIR}/${PORTNAME}-core-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_ACTION=${GEMS_DIR}/${PORTNAME}-action-args-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_ACTION=${DOC_DIR}/${PORTNAME}-action-args-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_ASSETS=${GEMS_DIR}/${PORTNAME}-assets-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_ASSETS=${DOC_DIR}/${PORTNAME}-assets-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_GEN=${GEMS_DIR}/${PORTNAME}-gen-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_GEN=${DOC_DIR}/${PORTNAME}-gen-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_HAML=${GEMS_DIR}/${PORTNAME}-haml-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_HAML=${DOC_DIR}/${PORTNAME}-haml-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_BUILDER=${GEMS_DIR}/${PORTNAME}-builder-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_BUILDER=${DOC_DIR}/${PORTNAME}-builder-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_PARTS=${GEMS_DIR}/${PORTNAME}-parts-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_PARTS=${DOC_DIR}/${PORTNAME}-parts-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_CACHE=${GEMS_DIR}/${PORTNAME}-cache-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_CACHE=${DOC_DIR}/${PORTNAME}-cache-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_MAILER=${GEMS_DIR}/${PORTNAME}-mailer-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_MAILER=${DOC_DIR}/${PORTNAME}-mailer-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_FREEZER=${GEMS_DIR}/${PORTNAME}-freezer-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_FREEZER=${DOC_DIR}/${PORTNAME}-freezer-${PORTVERSION}
PLIST_SUB+=	GEM_LIB_DIR_MORE=${GEMS_DIR}/${PORTNAME}-more-${PORTVERSION}
PLIST_SUB+=	GEM_DOC_DIR_MORE=${DOC_DIR}/${PORTNAME}-more-${PORTVERSION}

.include <bsd.port.mk>
