# New ports collection makefile for:	smail
# Version required:	3.2
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.20 1998/01/25 20:45:14 torstenb Exp $
#

DISTNAME=	smail-3.2.0.101
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/ \
		ftp://ftp.planix.com/pub/Smail/ \
		ftp://ftp.fu-berlin.de/unix/mail/smail/

MAINTAINER=	torstenb@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libident.a:${PORTSDIR}/security/libident
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper

INSTALL_TARGET=	install installman

MAN1=		pathto.1 uuwho.1 uupath.1
MAN5=		smailconf.5 smail.5 smaildrct.5 smailmeth.5 smailqual.5 \
		smailrtrs.5 smailrtry.5 smailtrns.5 
MAN8=		pathalias.8 mkdbm.8 mkline.8 mksort.8 mkaliases.8 smail.8 \
		mkpath.8 pathmerge.8 checkerr.8 getmap.8 mkhpath.8 savelog.8 \
		mkuuwho.8 mailq.8 sendmail.8 runq.8 rmail.8 rsmtp.8 smtpd.8

post-install:
	@echo "If you want to replace sendmail with links to smail, type"
	@echo "the following command as \"root\":"
	@echo ""
	@echo "      make replace"

replace:
	@echo "===> Replacing sendmail"
	if [ -e /usr/sbin/sendmail ]; then \
		mv -f /usr/sbin/sendmail /usr/sbin/sendmail.BAK; \
		if [ -f /usr/sbin/sendmail.BAK ]; then \
			chmod 0 /usr/sbin/sendmail.BAK; \
		fi;\
	fi
	if [ -e /usr/local/bin/smail ]; then \
		cp -fp /usr/local/bin/smail /usr/sbin/sendmail; \
	fi
	if [ -f /usr/sbin/mailstats ]; then \
		chmod 0 /usr/sbin/mailstats; \
	fi
	if [ -e /usr/bin/newaliases ]; then \
		mv -f /usr/bin/newaliases /usr/bin/newaliases.BAK; \
		if [ -f /usr/bin/newaliases.BAK ]; then \
			chmod 0 /usr/bin/newaliases.BAK; \
		fi;\
	fi
	if [ -e /usr/local/bin/newaliases ]; then \
		cp -fp /usr/local/bin/newaliases /usr/bin/newaliases; \
	fi
	if [ -e /usr/bin/mailq ]; then \
		mv -f /usr/bin/mailq /usr/bin/mailq.BAK; \
		if [ -f /usr/bin/mailq.BAK ]; then \
			chmod 0 /usr/bin/mailq.BAK; \
		fi;\
	fi
	if [ -e /usr/local/bin/mailq ]; then \
		cp -fp /usr/local/bin/mailq /usr/bin/mailq; \
	fi

.include <bsd.port.mk>
