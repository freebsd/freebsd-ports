# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	namefix
PORTVERSION=	4.0.2
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}.pl/${PORTVERSION}
DISTNAME=	${PORTNAME}.pl_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Batch file renamer

LICENSE=	GPLv2

RUN_DEPENDS=	p5-MP3-Tag>=0:audio/p5-MP3-Tag \
		p5-Tk>=0:x11-toolkits/p5-Tk \
		p5-Tk-JComboBox>=0:x11-toolkits/p5-Tk-JComboBox \
		p5-Tk-DynaTabFrame>=0:x11-toolkits/p5-Tk-DynaTabFrame

WRKSRC=		${WRKDIR}/${PORTNAME}.pl
NO_BUILD=	yes
NO_ARCH=	yes

USES=		7z perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	namefix-cli.pl namefix.pl

do-configure:
.for bin in ${PORTNAME} ${PORTNAME}-cli
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/${bin}.in
	@${ECHO_CMD} 'namefix_dir=${PREFIX}/${SITE_PERL_REL}/${PORTNAME}' \
		>> ${WRKDIR}/${bin}.in
	@${ECHO_CMD} 'cd $${namefix_dir}; exec ./${bin}.pl $$@' \
		>> ${WRKDIR}/${bin}.in
.endfor

do-install:
.for bin in ${PORTNAME} ${PORTNAME}-cli
	${INSTALL_SCRIPT} ${WRKDIR}/${bin}.in ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
.for data in ${PORTNAME} ${PORTNAME}-cli
	${INSTALL_SCRIPT} ${WRKSRC}/${data}.pl \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/mem.jpg \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
.for dir in libs libs/cli libs/gui
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/${dir}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/txt
	${INSTALL_DATA} ${WRKSRC}/txt/*.txt \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/txt

.include <bsd.port.mk>
