# New ports collection makefile for:	ssmtp
# Date created:		9 Jan 2001
# Whom:			Tomasz Paszkowski <ns88@k.pl>
#
# $FreeBSD$
#

PORTNAME=	ssmtp
PORTVERSION=	2.60.3
CATEGORIES=	mail
MASTER_SITES=	http://ftp.us.debian.org/debian/%SUBDIR%/ \
		http://http.us.debian.org/debian/%SUBDIR%/ \
		http://ftp.debian.org/debian/%SUBDIR%/ \
		http://ftp.egr.msu.edu/debian/%SUBDIR%/ \
		http://mirrors.kernel.org/debian/%SUBDIR%/ \
		http://archive.progeny.com/debian/%SUBDIR%/ \
		http://debian.crosslink.net/debian/%SUBDIR%/ \
		http://ftp-mirror.internap.com/pub/debian/%SUBDIR%/ \
		http://ftp.cerias.purdue.edu/pub/os/debian/%SUBDIR%/ \
		http://ftp.lug.udel.edu/debian/%SUBDIR%/ \
		http://debian.lcs.mit.edu/debian/%SUBDIR%/ \
		http://debian.teleglobe.net/%SUBDIR%/ \
		http://debian.rutgers.edu/%SUBDIR%/ \
		http://debian.oregonstate.edu/debian/%SUBDIR%/ \
		http://mirrors.terrabox.com/debian/%SUBDIR%/ \
		http://ftp.de.debian.org/debian/%SUBDIR%/ \
		http://ftp.at.debian.org/debian/%SUBDIR%/ \
		http://ftp.bg.debian.org/debian/%SUBDIR%/ \
		http://ftp.cz.debian.org/debian/%SUBDIR%/ \
		http://ftp.dk.debian.org/debian/%SUBDIR%/ \
		http://ftp.ee.debian.org/debian/%SUBDIR%/ \
		http://ftp.fi.debian.org/debian/%SUBDIR%/ \
		http://ftp.fr.debian.org/debian/%SUBDIR%/ \
		http://ftp.hr.debian.org/debian/%SUBDIR%/ \
		http://ftp.hu.debian.org/debian/%SUBDIR%/ \
		http://ftp.ie.debian.org/debian/%SUBDIR%/ \
		http://ftp.is.debian.org/debian/%SUBDIR%/ \
		http://ftp.it.debian.org/debian/%SUBDIR%/ \
		http://ftp.nl.debian.org/debian/%SUBDIR%/ \
		http://ftp.no.debian.org/debian/%SUBDIR%/ \
		http://ftp.pl.debian.org/debian/%SUBDIR%/ \
		http://ftp.si.debian.org/debian/%SUBDIR%/ \
		http://ftp.es.debian.org/debian/%SUBDIR%/ \
		http://ftp.se.debian.org/debian/%SUBDIR%/ \
		http://ftp.tr.debian.org/debian/%SUBDIR%/ \
		http://ftp.uk.debian.org/debian/%SUBDIR%/ \
		http://ftp.au.debian.org/debian/%SUBDIR%/ \
		http://ftp.wa.au.debian.org/debian/%SUBDIR%/ \
		http://ftp.nz.debian.org/debian/%SUBDIR%/ \
		http://ftp.jp.debian.org/debian/%SUBDIR%/ \
		http://linux.csie.nctu.edu.tw/debian/%SUBDIR%/ \
		http://debian.linux.org.tw/debian/%SUBDIR%/ \
		http://linux.cdpa.nsysu.edu.tw/debian/%SUBDIR%/ \
		http://ftp.br.debian.org/debian/%SUBDIR%/ \
		http://ftp.cl.debian.org/debian/%SUBDIR%/
MASTER_SITE_SUBDIR=	pool/main/s/ssmtp
DISTNAME=	ssmtp_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extremely simple MTA to get mail off the system to a mail hub

WRKSRC=		${WRKDIR}/ssmtp-2.60

USE_OPENSSL=	yes

GNU_CONFIGURE=  yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--enable-ssl --enable-inet6

MAN8=		ssmtp.8

post-configure:
	@${REINPLACE_CMD} -e "s,/etc/ssl/certs/ssmtp.pem,${PREFIX}/etc/ssmtp/ssmtp.pem,g" \
		${WRKSRC}/ssmtp.c ${WRKSRC}/ssmtp.conf
	@${REINPLACE_CMD} -e "s, /etc, ${PREFIX}/etc,g" ${WRKSRC}/ssmtp.8

replace:
	@${REINPLACE_CMD} -e 's,^[^#],#&,g' /etc/mail/mailer.conf
	@${ECHO_CMD} "sendmail	${PREFIX}/sbin/ssmtp" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "send-mail	${PREFIX}/sbin/ssmtp" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "mailq		${PREFIX}/sbin/ssmtp" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "newaliases	${PREFIX}/sbin/ssmtp" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "hoststat	/usr/bin/true" >> /etc/mail/mailer.conf
	@${ECHO_CMD} "purgestat	/usr/bin/true" >> /etc/mail/mailer.conf

post-install:
	@${ECHO_MSG} --------------------------------------------------
	@${ECHO_MSG}
	@${ECHO_MSG} "To replace sendmail with ssmtp type make replace"
	@${ECHO_MSG}
	@${ECHO_MSG} --------------------------------------------------
	@${SED} -e 's#/etc#${PREFIX}/etc#' ${PKGMESSAGE}

.include <bsd.port.mk>
