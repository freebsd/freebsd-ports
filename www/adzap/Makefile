# New ports collection makefile for:	adzap
# Date created:		03 March 2001
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	adzap
PORTVERSION=	20010417
CATEGORIES=	www perl5
MASTER_SITES=	http://www.zip.com.au/~cs/adzap/

MAINTAINER=	kris@FreeBSD.org

WRKSRC=		${WRKDIR}/adzap

NO_BUILD=	# defined
USE_PERL5=	# defined

do-configure:
.for FILE in squid_redirect wrapzap
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.orig
	${SED} -e "s:/usr/bin/perl:${PERL5}:g" \
	       -e "s:@@PREFIX@@:${PREFIX}:g" \
		<${WRKSRC}/${FILE}.orig >${WRKSRC}/${FILE}
.endfor
#	${SED} s,%PREFIX%,${PREFIX}, < ${WRKSRC}/wrapzap > ${WRKSRC}/adzap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/squid_redirect ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/wrapzap ${PREFIX}/libexec/adzap
	${MKDIR} ${PREFIX}/share/examples/adzap
.for FILE in adzap.conf proxy-cisra.pac proxy-home.pac proxy-zip.pac \
	closepopup-clear.html no-op-clear.html closepopup.html no-op.html \
	no-op-clear.js no-op.js ad-clear.gif ad.gif
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/examples/adzap
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
