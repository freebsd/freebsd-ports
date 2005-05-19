# New ports collection makefile for:	adzap
# Date created:		03 March 2001
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	adzap
PORTVERSION=	20050517
CATEGORIES=	www perl5
MASTER_SITES=	http://adzapper.sourceforge.net/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=kris

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Filter out animated ad banners from web pages

WRKSRC=		${WRKDIR}/adzap

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes

ZAPFILES=	ad-clear.gif ad-clear.mp3 ad-clear.swf ad-grey.gif \
		ad-old.gif ad.gif ad.mp3 ad.swf adbg-clear.gif adbg.gif \
		closepopup-clear.html closepopup.html counter-clear.gif \
		counter.gif no-op-clear.html no-op-clear.js \
		no-op-counter-clear.html no-op-counter-clear.js \
		no-op-counter.html no-op-counter.js no-op.html no-op.js \
		webbug-clear.gif webbug-clear.js webbug.gif webbug.js \
		adzap.conf

RCFILES=	proxy-home.pac proxy-zip.pac

do-configure:
.for FILE in squid_redirect wrapzap
	${REINPLACE_CMD} -e "s:/usr/bin/perl:${PERL5}:g" \
			-e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/scripts/${FILE}
.endfor
	${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/zaps/adzap.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap ${PREFIX}/libexec/adzap
	${MKDIR} ${PREFIX}/share/examples/adzap
.for FILE in ${ZAPFILES}
	${INSTALL_DATA} ${WRKSRC}/zaps/${FILE} ${EXAMPLESDIR}
.endfor
.for FILE in ${RCFILES}
	${INSTALL_DATA} ${WRKSRC}/rc/${FILE} ${EXAMPLESDIR}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
