# New ports collection makefile for:	translate-toolkit
# Date created:		30 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	translate-toolkit
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/translate

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Converts between many translation formats

BUILD_DEPENDS=	py*-levenshtein>=0:${PORTSDIR}/devel/py-levenshtein \
		iso-codes>=1.3:${PORTSDIR}/misc/iso-codes \
		bash:${PORTSDIR}/shells/bash \
		py*-elementtree>=0:${PORTSDIR}/devel/py-elementtree \
		msghack:${PORTSDIR}/devel/gettext-msghack
RUN_DEPENDS:=	${BUILD_DEPENDS}
# Can use psyco (on i386)
# po2html may require utidylib

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
MAN1_=	csv2po csv2tbx html2po lookupservice moz2po oo2po po2csv\
	po2html po2moz po2oo po2prop po2tmx po2ts po2txt po2xliff poclean pocompile\
	poconflicts podebug pofilter pogrep pomerge porestructure poswap pot2po prop2po\
	sxw2po ts2po txt2po xliff2po
MAN1=	${MAN1_:S|$|.1|}

#PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --record=${WRKSRC}/install.log
#PORT_VERBS!=	ls ./*/*/build/scripts*/
PORT_VERBS+=	translate

post-patch:
	@${REINPLACE_CMD} -e '1s|/bin/bash|${LOCALBASE}&|;s|mktemp|mktemp -t /tmp|'\
		${WRKSRC}/tools/*

post-build:
	@${MKDIR} ${WRKDIR}/manpages/
	@cd ${WRKSRC}/build/scripts*/&&for i in ${MAN1_};do\
		${SETENV} PYTHONPATH=${WRKSRC}/build/lib \
			${PYTHON_CMD} $$i --man>${WRKDIR}/manpages/$$i.1;done

post-install:
	@cd ${WRKDIR}/manpages/&&${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/

list-man1:	build
	@cd ${WRKSRC}/build/scripts*/&&${GREP} -l "${PYTHON_CMD}" *|\
		${EGREP} -v '(lookupclient|pocount)'|${TR} "\n" " "

.include <bsd.port.mk>
