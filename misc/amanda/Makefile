# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	amanda
PORTVERSION=	2.3.0.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/amanda/old-versions/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=yes
CONFIGURE_ARGS+=--with-dbdir=/var/log/amanda --with-logdir=/var/log/amanda \
		--libexecdir=${PREFIX}/libexec/amanda --with-mmap \
		--with-user=operator --with-group=operator

MAN8=		amadmin.8 amanda.8 amcheck.8 amcleanup.8 amdump.8 amflush.8 \
		amlabel.8 amplot.8 amrecover.8 amrestore.8 amrmtape.8 amtape.8 \
		amtoc.8

LIBEXEC_BIN=	amandad amcat.awk amgetidx amidxtaped amindexd amplot.awk \
		amplot.g amplot.gp amtrmidx calcsize chg-generic \
		createindex-dump createindex-gnutar driver dumper getconf \
		hp-changer no-changer patch-system planner reporter \
		rth-changer rundump runtar selfcheck sendbackup-dump \
		sendbackup-gnutar sendindex sendsize taper versionsuffix

BIN_BIN=	amadmin amcheck amcheckdb amcleanup amdump amflush amlabel \
		amoverview amplot amrecover amrestore amrmtape amtape amtoc \
		amverify

INSTALL_DATA=	amanda.conf chg-generic.conf disklist

post-install:
	@${MKDIR} ${PREFIX}/share/examples/amanda
	${INSTALL_DATA} ${WRKSRC}/example/amanda.conf ${PREFIX}/share/examples/amanda
	${INSTALL_DATA} ${WRKSRC}/example/chg-generic.conf ${PREFIX}/share/examples/amanda
	${INSTALL_DATA} ${WRKSRC}/example/disklist ${PREFIX}/share/examples/amanda
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${MKDIR} ${PREFIX}/etc/amanda
	@${MKDIR} /var/log/amanda
	@${TOUCH} /var/log/amanda/curinfo

.include <bsd.port.mk>
