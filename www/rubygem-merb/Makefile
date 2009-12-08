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

BROKEN=		fails to install
DEPRECATED=	has been broken for 5 months
EXPIRATION_DATE=2010-01-08

USE_RUBY=	yes
USE_RUBYGEMS=	yes
PLIST_FILES=	bin/merb \
		bin/merb-gen \
		bin/frozen-merb

MERB_MODULES=	action-args	\
		assets		\
		builder		\
		cache		\
		core		\
		freezer		\
		gen		\
		haml		\
		mailer		\
		more		\
		parts

post-install:
.for M in ${MERB_MODULES:S,^,merb-,g:S,$,-${PORTVERSION},g} merb-${PORTVERSION}
	@${ECHO} ${CACHE_DIR}/${M}.gem >> ${TMPPLIST}
	@${ECHO} ${SPEC_DIR}/${M}.gemspec >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${DOC_DIR}/${M} -type f \
		-print | ${SED} -E -e 's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${DOC_DIR}/${M} -type d \
		-print | ${SED} -E -e 's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${GEMS_DIR}/${M} -type f \
		-print | ${SED} -E -e 's,^${PREFIX}/?,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${GEMS_DIR}/${M} -type d \
		-print | ${SED} -E -e 's,^${PREFIX}/?,@dirrm ,' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@unexec rmdir %D/${GEMS_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${DOC_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${CACHE_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${SPEC_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${GEMS_BASE_DIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby/gems 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/lib/ruby 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
