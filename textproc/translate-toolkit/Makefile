# New ports collection makefile for:	translate-toolkit
# Date created:		30 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	translate-toolkit
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/translate/Translate%20Toolkit/${PORTVERSION} \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts between many translation formats

BUILD_DEPENDS=	py*-pysqlite>=2.3:${PORTSDIR}/databases/py-pysqlite23 \
		py*-vobject>=0:${PORTSDIR}/deskutils/py-vobject \
		msghack:${PORTSDIR}/devel/gettext-msghack \
		py*-elementtree>=0:${PORTSDIR}/devel/py-elementtree \
		py*-iniparse>=0:${PORTSDIR}/devel/py-iniparse \
		py*-levenshtein>=0:${PORTSDIR}/devel/py-levenshtein \
		py*-lxml>=0:${PORTSDIR}/devel/py-lxml \
		iso-codes>=1.3:${PORTSDIR}/misc/iso-codes \
		bash:${PORTSDIR}/shells/bash \
		py*-utidy>=0:${PORTSDIR}/www/py-utidy
RUN_DEPENDS:=	${BUILD_DEPENDS}
# Can use psyco (on i386)

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		csv2po.1 csv2tbx.1 html2po.1 ical2po.1 ini2po.1 \
		lookupservice.1 moz2po.1 odf2xliff.1 oo2po.1 oo2xliff.1 \
		php2po.1 po2csv.1 po2html.1 po2ical.1 po2ini.1 \
		po2moz.1 po2oo.1 po2php.1 po2prop.1 po2rc.1 \
		po2symb.1 po2tiki.1 po2tmx.1 po2ts.1 po2txt.1 \
		po2web2py.1 po2wordfast.1 po2xliff.1 poclean.1 pocompile.1 \
		poconflicts.1 podebug.1 pofilter.1 pogrep.1 pomerge.1 \
		porestructure.1 posegment.1 poswap.1 pot2po.1 pretranslate.1 \
		prop2po.1 rc2po.1 symb2po.1 tiki2po.1 ts2po.1 \
		txt2po.1 web2py2po.1 xliff2odf.1 xliff2oo.1 xliff2po.1

post-patch:
	@${FIND} ${WRKSRC}/tools -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|mktemp|mktemp -t /tmp|'

post-build:
	@${MKDIR} ${WRKDIR}/manpages
.for i in ${MAN1:S|.1||}
	cd ${WRKSRC}/build/scripts-* && \
		${SETENV} PYTHONPATH=${WRKSRC}/build/lib ${PYTHON_CMD} \
			${i} --man > ${WRKDIR}/manpages/${i}.1
.endfor

post-install:
.for i in ${MAN1}
	cd ${WRKDIR}/manpages && ${INSTALL_MAN} ${i} ${MANPREFIX}/man/man1
.endfor

list-man1:	build
	@cd ${WRKSRC}/build/scripts-* && ${GREP} -l "${PYTHON_CMD}" * | \
		${EGREP} -v '(build_tmdb|pocount|poterminology|tmserver)' | \
		${TR} "\n" " "

.include <bsd.port.mk>
