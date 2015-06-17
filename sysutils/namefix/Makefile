# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	namefix
PORTVERSION=	4.0.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}.pl/${PORTVERSION}
DISTNAME=	${PORTNAME}.pl_${PORTVERSION}
EXTRACT_SUFX=	.7z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Batch renamer

LICENSE=	GPLv2

EXTRACT_DEPENDS=7z:${PORTSDIR}/archivers/p7zip
RUN_DEPENDS=	p5-MP3-Tag>=0:${PORTSDIR}/audio/p5-MP3-Tag \
		p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-JComboBox>=0:${PORTSDIR}/x11-toolkits/p5-Tk-JComboBox \
		p5-Tk-DynaTabFrame>=0:${PORTSDIR}/x11-toolkits/p5-Tk-DynaTabFrame

EXTRACT_CMD=	7z
EXTRACT_BEFORE_ARGS=	x
EXTRACT_AFTER_ARGS=	-bd -y >/dev/null 2>&1

WRKSRC=		${WRKDIR}/${PORTNAME}.pl
NO_BUILD=	yes
NO_ARCH=	yes

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	namefix-cli.pl namefix.pl

do-configure:
.for bin in ${PORTNAME} ${PORTNAME}-cli
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/${bin}.in
	@${ECHO_CMD} 'namefix_dir=${PREFIX}/${SITE_PERL_REL}/${PORTNAME}' >> ${WRKDIR}/${bin}.in
	@${ECHO_CMD} 'cd $${namefix_dir}; exec ./${bin}.pl $$@' >> ${WRKDIR}/${bin}.in
.endfor

do-install:
.for bin in ${PORTNAME} ${PORTNAME}-cli
	${INSTALL_SCRIPT} ${WRKDIR}/${bin}.in ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
.for data in ${PORTNAME} ${PORTNAME}-cli
	${INSTALL_SCRIPT} ${WRKSRC}/${data}.pl ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/mem.jpg ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}
.for dir in libs libs/cli libs/gui
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/${dir}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/txt
	${INSTALL_DATA} ${WRKSRC}/txt/*.txt ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/${PORTNAME}/txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
