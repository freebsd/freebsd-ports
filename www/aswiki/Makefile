# New ports collection makefile for:	ruby-aswiki
# Date created:		13 June 2003
# Whom:			Makoto Matsushita <matusita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		aswiki
PORTVERSION=		1.0.2
PORTREVISION=		1
CATEGORIES=		www ruby
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		matusita@FreeBSD.org
COMMENT=		WikiWikiWeb clone written in Ruby

RUN_DEPENDS=		${RUBY_SITELIBDIR}/amrita/xml.rb:${PORTSDIR}/textproc/ruby-amrita \
			${RUBY_SITELIBDIR}/algorithm/diff.rb:${PORTSDIR}/textproc/ruby-diff \
			${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

NO_BUILD=		YES
USE_REINPLACE=		YES

USE_RUBY=		YES
RUBY_SHEBANG_FILES=	aswiki.cgi
USE_RUBY_FEATURES=	strscan

post-extract:
	${CP} ${FILESDIR}/setup.sh ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e "s|__DATADIR__|${DATADIR}|" ${WRKSRC}/setup.sh
	${ECHO} "\$$DIR_TEMPLATE = '__DATADIR__/template'" \
						>> ${WRKSRC}/aswiki.conf
	${ECHO} "\$$DIR_PLUGIN = '__DATADIR__/plugin'" \
						>> ${WRKSRC}/aswiki.conf
	${REINPLACE_CMD} -e "s|^# \\$$|\\$$|" -e "s|__DATADIR__|${DATADIR}|" \
		-e "s|\\A(\?:|\\A(|" ${WRKSRC}/aswiki.conf
	${FIND} ${PATCH_WRKSRC} -name '*.orig' -delete

do-install:
	# Ruby libraries
	${CP} -R ${WRKSRC}/aswiki ${RUBY_SITELIBDIR}/${PORTNAME}
	# Data files
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/aswiki.cgi ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/aswiki.conf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/default.css ${DATADIR}
	${CP} -R ${WRKSRC}/plugin ${DATADIR}
	${CP} -R ${WRKSRC}/template ${DATADIR}
	# Setup script
	${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${DATADIR}

.include <bsd.port.mk>
