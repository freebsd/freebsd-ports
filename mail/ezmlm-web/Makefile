# New ports collection makefile for:	ezmlm-web
# Date Created: 			18 May 2000
# Whom: 				Guy Antony Halse <guy@rucus.ru.za.za>
#
# $FreeBSD$
#

PORTNAME=	ezmlm-web
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	ftp://rucus.ru.ac.za/pub/mail/ezmlm/

MAINTAINER=	guy-ezmlm@rucus.ru.ac.za

BUILD_DEPENDS=	${LOCALBASE}/${EZMLM_DIR}/bin/ezmlm-idx:${PORTSDIR}/mail/ezmlm-idx \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Ezmlm.pm:${PORTSDIR}/mail/p5-Mail-Ezmlm
RUN_DEPENDS=	${LOCALBASE}/sbin/apachectl:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools

# Change these to suit your setup. You can do this via the environment
# CGI_BIN is the location relative to ${PREFIX} of your webservers' cgi-bin
# EZMLM_DIR is the base relative to ${PREFIX} in which ezmlm was installed
#
CGI_BIN?=	www/cgi-bin.default
EZMLM_DIR?=

USE_PERL5=	YES
PLIST_SUB=	CGI_BIN=${CGI_BIN:S/$/\//:S/^\///} EZMLM_DIR=${EZMLM_DIR:S/$/\//:S/^\///}

do-build:
	@cd ${WRKSRC}; ${MAKE} index; ${MV} index ezmlm-web

do-install:
	${MKDIR} ${PREFIX}/${CGI_BIN} ${PREFIX}/${EZMLM_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ezmlm-web.cgi ${PREFIX}/${EZMLM_DIR}/bin
	${INSTALL_DATA} ${WRKSRC}/ezmlmwebrc ${PREFIX}/${EZMLM_DIR}/etc/ezmlm/ezmlmwebrc.sample
	${INSTALL_PROGRAM} -o alias -g qmail -m 4755 ${WRKSRC}/ezmlm-web ${PREFIX}/${CGI_BIN}
	${MKDIR} ${PREFIX}/share/ezmlm-web
.for file in CHANGES README index.c htaccess.sample webusers.sample
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/ezmlm-web
.endfor

post-install:
	@${SED} 's!%%PREFIX%%!${PREFIX}!g; s!%%EZMLM_DIR%%!${PREFIX}${EZMLM_DIR:S/^\///}!g' ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
