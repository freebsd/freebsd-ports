# New ports collection makefile for:    tdiary
# Date created:                 21 May 2003
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	1.5.6
CATEGORIES?=	www ruby
MASTER_SITES=	\
		${MASTER_SITE_SOURCEFORGE} \
		http://www.tdiary.org/download/
MASTER_SITE_SUBDIR=	sourceforge/${PORTNAME}
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	jfkimura@yahoo.co.jp
COMMENT=	A Web-based diary system (like weblog) written in Ruby

NO_BUILD=		yes
USE_RUBY=		yes
.if  !defined(WITHOUT_RUBY_FEATURES)
USE_RUBY_FEATURES=	fileutils
.endif

RUBY_SHEBANG_FILES=	index.rb update.rb misc/convert2.rb misc/posttdiary.rb misc/plugin/squeeze.rb \
misc/plugin/windex.rb misc/plugin/a/a_conf.rb misc/plugin/trackback/tb.rb

TDIARYDIR=	${EXAMPLESDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
.if  !defined(TDIARY_LANG)
TDIARY_LANG=	tdiary.conf-en
.endif

.if defined(WITH_TDIARY_UCONV)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
.endif
.if defined(WITH_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================================="
	@${ECHO_MSG} "When you chose plugin, it becomes necessary.  Use the following options:"
	@${ECHO_MSG} "  WITH_TDIARY_UCONV=yes	(RDF file creates  with UTF-8 : output_rdf.rb)"
	@${ECHO_MSG} "  WITH_TDIARY_NORA=yes	(Referer header support       : disp_referrer.rb)"
	@${ECHO_MSG} "============================================================================="
	@${ECHO_MSG}

do-install:
	@-${MKDIR} ${TDIARYDIR}
	@${SED} -e 's,@@@@PREFIX@@@@,${PREFIX},g' \
		-e 's,@@@@LANG@@@@,${TDIARY_LANG},g' \
		${FILESDIR}/tdiaryinst.rb.in > ${TDIARYDIR}/tdiaryinst.rb
	@${SED} -e 's,@@@@PREFIX@@@@,${PREFIX},g' \
		-e 's,@@@@LANG@@@@,${TDIARY_LANG},g' \
		${FILESDIR}/tdiary-FreeBSD.sh.in > ${TDIARYDIR}/tdiary-FreeBSD.sh
	@${CHMOD} ugo=rx ${TDIARYDIR}/tdiary-FreeBSD.sh
	@${CP} -pR ${WRKSRC}/ ${TDIARYDIR}
.if ${TDIARY_LANG} == tdiary.conf-en
	@${ECHO_MSG} "===>  TDIARY : English Language messages support"
	@${RUBY} -i -pe 'sub(/%Y-%m-%d/, "%Y-%m-%d [%a]")' ${TDIARYDIR}/misc/i18n/tdiary.conf.sample-en
.else
	@${ECHO_MSG} "===>  TDIARY : Japanese Language messages support"
	@${RUBY} -i -pe 'sub(/%Y-%m-%d/, "%Y-%m-%d [%J]")' ${TDIARYDIR}/tdiary.conf.sample
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TDIARYDIR}

post-install:
	@cd ${WRKSRC} && ${FIND} . -type f -o -type l | ${SED} -e 's,^\.,${TDIARYDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${FIND} . -type d -depth  | ${SED} -e 's,^\.,@dirrm ${TDIARYDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
	@${SED} -e "s,%%EXAMPLESDIR%%,${EXAMPLESDIR},g" ${PKGMESSAGE}

.include <bsd.port.mk>
