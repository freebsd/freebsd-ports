# New ports collection makefile for:	wwwoffle
# Version required:	2.4
# Date created:		1 Jun 1998
# Whom:			Peter Mutsaers
#
# $FreeBSD$
#

DISTNAME=	wwwoffle-2.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/servers
EXTRACT_SUFX=	.tgz

MAINTAINER=	aw1@stade.co.uk

USE_GMAKE=	yes
USE_PERL5=	yes

MAN1=		wwwoffle.1
MAN5=		wwwoffle.conf.5
MAN8=		wwwoffled.8

SPOOL=		/var/spool

MAKE_ENV+=	SPOOL=$(SPOOL)

do-install:
	#programs
	[ -x $(PREFIX)/bin ] || $(INSTALL) -d $(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/wwwoffle $(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/upgrade-cache $(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/endian-cache $(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/wwwoffle-tools $(PREFIX)/bin
	${LN} -sf wwwoffle-tools $(PREFIX)/bin/wwwoffle-ls
	${LN} -sf wwwoffle-tools $(PREFIX)/bin/wwwoffle-mv
	${LN} -sf wwwoffle-tools $(PREFIX)/bin/wwwoffle-rm
	${LN} -sf wwwoffle-tools $(PREFIX)/bin/wwwoffle-read
	${LN} -sf wwwoffle-tools $(PREFIX)/bin/wwwoffle-write
	[ -x $(PREFIX)/sbin ] || $(INSTALL) -d $(PREFIX)/sbin
	$(INSTALL_PROGRAM) $(WRKSRC)/wwwoffled $(PREFIX)/sbin
	# man pages
	[ -x $(PREFIX)/man ] || $(INSTALL) -d $(PREFIX)/man
	[ -x $(PREFIX)/man/man1 ] || $(INSTALL) -d $(PREFIX)/man/man1
	$(INSTALL_MAN)  $(WRKSRC)/wwwoffle.man $(PREFIX)/man/man1/wwwoffle.1
	[ -x $(PREFIX)/man/man5 ] || $(INSTALL) -d $(PREFIX)/man/man5
	$(SED) -e 's%SPOOLDIR%$(SPOOL)/wwwoffle%' -e 's%CONFDIR%$(SPOOL)/wwwoffle%' < $(WRKSRC)/wwwoffle.conf.man > $(WRKSRC)/wwwoffle.conf.man.install
	$(INSTALL_MAN) $(WRKSRC)/wwwoffle.conf.man.install $(PREFIX)/man/man5/wwwoffle.conf.5
	[ -x $(PREFIX)/man/man8 ] || $(INSTALL) -d $(PREFIX)/man/man8
	$(INSTALL_MAN) $(WRKSRC)/wwwoffled.man $(PREFIX)/man/man8/wwwoffled.8
	[ -x $(PREFIX)/doc/wwwoffle ] || $(INSTALL) -d $(PREFIX)/doc/wwwoffle
	# documentation
	$(INSTALL_DATA) \
		$(WRKSRC)/CHANGES.CONF \
		$(WRKSRC)/CONVERT \
		$(WRKSRC)/COPYING \
		$(WRKSRC)/FAQ \
		$(WRKSRC)/INSTALL \
		$(WRKSRC)/NEWS \
		$(WRKSRC)/README \
		$(WRKSRC)/README.1st \
		$(WRKSRC)/README.CONF \
		$(WRKSRC)/README.PWD \
		$(WRKSRC)/README.htdig \
		$(WRKSRC)/UPGRADE \
		$(PREFIX)/doc/wwwoffle
	# initial configuration file
	[ -x $(SPOOL)/wwwoffle ] || $(INSTALL) -d $(SPOOL)/wwwoffle
	$(SED) -e 's%SPOOLDIR%$(SPOOL)/wwwoffle%' -e 's%CONFDIR%$(SPOOL)/wwwoffle%' < $(WRKSRC)/wwwoffle.conf > $(WRKSRC)/wwwoffle.conf.install
	$(INSTALL_DATA) $(WRKSRC)/wwwoffle.conf.install $(SPOOL)/wwwoffle/wwwoffle.conf.install
	# html files to holding directory
	[ -x $(SPOOL)/wwwoffle/hold ] || $(INSTALL) -d $(SPOOL)/wwwoffle/hold
	tar cf - -C $(WRKSRC) html | tar xf - -C $(SPOOL)/wwwoffle/hold
	# configuration upgrade script to holding directory
	$(INSTALL_SCRIPT) $(WRKSRC)/upgrade-config.pl $(SPOOL)/wwwoffle/hold
	# startup script
	[ -x $(PREFIX)/etc/rc.d ] || $(INSTALL) -d $(PREFIX)/etc/rc.d
	$(SED) -e 's:%PREFIX%:$(PREFIX):g' $(FILESDIR)/wwwoffled.sh > $(WRKDIR)/wwwoffled.sh
	$(INSTALL_SCRIPT) $(WRKDIR)/wwwoffled.sh $(PREFIX)/etc/rc.d

post-install:
	# upgrade cache, convert cache, build additional files, configure html and wwwoffle.conf
	$(SH) $(PKGDIR)/INSTALL ${DISTNAME} POST-INSTALL

# keep at end
.include <bsd.port.mk>
