# New ports collection makefile for:	adzap
# Date created:		03 March 2001
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	adzap
PORTVERSION=	20020125
CATEGORIES=	www perl5
MASTER_SITES=	http://www.zip.com.au/~cs/adzap/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=kris

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/adzap

NO_BUILD=	# defined
USE_PERL5=	# defined
ZAPFILES=	adzap.conf closepopup-clear.html no-op-clear.html \
		closepopup.html no-op.html no-op-clear.js no-op.js \
		ad-clear.gif ad-clear.mp3 ad-clear.swf ad.gif
RCFILES=	proxy-cisra.pac proxy-home.pac proxy-zip.pac

do-configure:
.for FILE in squid_redirect wrapzap
	${PERL} -pi -e "s:/usr/bin/perl:${PERL5}:g; \
			s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/scripts/${FILE}
	${PERL} -pi -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/zaps/adzap.conf
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap ${PREFIX}/libexec/adzap
	${MKDIR} ${PREFIX}/share/examples/adzap
.for FILE in ${ZAPFILES}
	${INSTALL_DATA} ${WRKSRC}/zaps/${FILE} ${PREFIX}/share/examples/adzap
.endfor
.for FILE in ${RCFILES}
	${INSTALL_DATA} ${WRKSRC}/rc/${FILE} ${PREFIX}/share/examples/adzap
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
