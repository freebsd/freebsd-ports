# New ports collection makefile for:	ezmlm-web
# Date Created: 			18 May 2000
# Whom: 				Guy Antony Halse <guy@rucus.ru.za.za>
#
# $FreeBSD$
#

PORTNAME=	ezmlm-web
PORTVERSION= 	2.0
CATEGORIES=	mail www
MASTER_SITES=	ftp://rucus.ru.ac.za/pub/mail/ezmlm/

MAINTAINER=	guy-ezmlm@rucus.ru.ac.za

BUILD_DEPENDS=	${EZMLM_DIR}/bin/ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Ezmlm.pm:${PORTSDIR}/mail/p5-Mail-Ezmlm
RUN_DEPENDS=	${LOCALBASE}/sbin/apache:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools

CGI_BIN?=	/share/apache/cgi-bin/
EZMLM_DIR?=	/

USE_PERL5=	YES
PLIST_SUB=	CGI_BIN=${CGI_BIN:S/\///} EZMLM_DIR=${EZMLM_DIR:S/\///}

do-build:
	@cd ${WRKSRC}; ${MAKE} index; ${MV} index ezmlm-web

do-install:
	${MKDIR} ${LOCALBASE}${CGI_BIN} ${LOCALBASE}${EZMLM_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ezmlm-web.cgi ${LOCALBASE}${EZMLM_DIR}/bin
	${INSTALL_DATA} ${WRKSRC}/ezmlmwebrc ${LOCALBASE}${EZMLM_DIR}/etc/ezmlm
	${INSTALL_PROGRAM} -o alias -g qmail -m 4755 ${WRKSRC}/ezmlm-web ${LOCALBASE}${CGI_BIN}
	${MKDIR} ${PREFIX}/share/ezmlm-web
.for file in CHANGES README index.c htaccess.sample webusers.sample
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/ezmlm-web
.endfor

post-install:
	@${SED} s!%%PREFIX%%!${PREFIX}!g ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
