# New ports collection makefile for:	smail
# Version required:	3.2
# Date created:		16 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.15 1996/11/18 09:02:59 torstenb Exp $
#

DISTNAME=	smail-3.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uu.net/networking/mail/smail/

MAINTAINER=	torstenb@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libident.a:${PORTSDIR}/security/libident

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
.if exists(/usr/sbin/sendmail)
	mv -f /usr/sbin/sendmail /usr/sbin/sendmail.BAK && chmod 0 \
		/usr/sbin/sendmail && cp -fp /usr/local/bin/smail \
		/usr/sbin/sendmail
.endif
.if exists(/usr/sbin/mailstats)
	chmod 0 /usr/sbin/mailstats
.endif
.if exists(/usr/bin/newaliases)
	mv -f /usr/bin/newaliases /usr/bin/newaliases.BAK && chmod 0 \
		/usr/bin/newaliases && cp -fp /usr/local/bin/newaliases \
		/usr/bin/newaliases
.endif
.if exists(/usr/bin/mailq)
	mv -f /usr/bin/mailq /usr/bin/mailq.BAK && chmod 0 \
		/usr/bin/mailq && cp -fp /usr/local/bin/mailq /usr/bin/mailq
.endif
	
.include <bsd.port.mk>
