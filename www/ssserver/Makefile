# New ports collection makefile for: ssserver
# Date created:		7 March 2000
# Whom:			support@kryltech.com
#
# $FreeBSD$
#

PORTNAME=	ssserver
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://www.kryltech.com/download/FreeBSD.x86.3/

MAINTAINER=	support@kryltech.com
COMMENT=	Adds the search capability to a Web site

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

INSTALL_RWDATA=	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m 666

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400000
LIB_DEPENDS+=	c.3:${PORTSDIR}/misc/compat3x
.endif

do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_PROGRAM} ${WRKSRC}/ssserver ${PREFIX}/www/cgi-bin
	@${INSTALL_PROGRAM} ${WRKSRC}/image ${PREFIX}/www/cgi-bin
	@${INSTALL_PROGRAM} ${WRKSRC}/ssserverdata/sssconf ${PREFIX}/www/cgi-bin/ssserverdata/sssconf
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Afrikaans.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Bulgarian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Catalan.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} "${WRKSRC}/ssserverdata/Chinese_Traditional(BIG5).ssl" ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Czech.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Danish.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Dutch.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/English.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Estonian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Finnish.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/French.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/German.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} "${WRKSRC}/ssserverdata/Greek(Latin).ssl" ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Greek.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Hebrew.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Hungarian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Icelandic.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Indonesian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Irish.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Italian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} "${WRKSRC}/ssserverdata/Japanese_Standard(ShiftJIS).ssl" ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} "${WRKSRC}/ssserverdata/Japanese(EUC).ssl" ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} "${WRKSRC}/ssserverdata/Korean(EUC).ssl" ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Latin.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Latvian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Lithuanian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Norwegian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Polish.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Portuguese.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Romanian.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} "${WRKSRC}/ssserverdata/Russian(KOI8-R).ssl" ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} "${WRKSRC}/ssserverdata/Russian(Windows).ssl" ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Slovak.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Spanish.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Swedish.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/Turkish.ssl ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/filelist.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/footer.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/header.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/help.htm ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/license.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/minus.gif ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/plus.gif ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/problems.htm ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_DATA} ${WRKSRC}/ssserverdata/readme.htm ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/ssserver.ini ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template1.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template2.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template3.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template4.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template5.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template6.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template7.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${INSTALL_RWDATA} ${WRKSRC}/ssserverdata/template8.txt ${PREFIX}/www/cgi-bin/ssserverdata
	@${CHMOD} -f 777 ${PREFIX}/www/cgi-bin/ssserverdata

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
