# New ports collection makefile for:	fpm
# Date created:				10 June 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	fpm
PORTVERSION=	0.59
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Figaro's Password Manager, an app to securely store your passwords

USE_GNOME=	gnomeprefix gnomehack gnomelibs
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

GPASSOURCE=	file.c librc2.c 
GPASVERS=	1.3.0
SOURCEFILES=	blowfish.c callbacks.c fpm.c fpm_clist.c fpm_crypt.c \
		fpm_gpw.c fpm_launcher.c fpm_pref.c import_gpasman.c \
		interface.c main.c md5.c passfile.c support.c
DOCS=		AUTHORS ChangeLog README TODO

GNOME_CFLAGS?=	`${GNOME_CONFIG} --cflags gnomeui` \
		`${LOCALBASE}/bin/xml-config --cflags`
GNOME_LIBS?=	`${GNOME_CONFIG} --libs gnomeui` \
		`${LOCALBASE}/bin/xml-config --libs`
CFLAGS+=	-DHAVE_CONFIG_H -I. -I.. ${GNOME_CFLAGS}

pre-build:
	${REINPLACE_CMD} -E -e "s@encrypt\(@bfishencrypt\(@g" ${WRKSRC}/src/blowfish.c

do-build:
.for f in ${GPASSOURCE}
	(cd ${WRKSRC}/src/gpasman-${GPASVERS}; ${CC} ${CFLAGS} ${GNOME_CFLAGS} -c ${f})
.endfor
.for f in ${SOURCEFILES}
	(cd ${WRKSRC}/src; ${CC} ${CFLAGS} ${GNOME_CFLAGS} -c ${f})
.endfor
	(cd ${WRKSRC}/src; ${CC} ${CFLAGS} -o fpm ${SOURCEFILES:S/.c/.o/g} \
	${GPASSOURCE:S/.c/.o/g:S/^/gpasman-${GPASVERS}\//g} ${GNOME_LIBS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/fpm ${PREFIX}/bin
	${INSTALL} -d -o root -g wheel -m 0755 \
	${PREFIX}/share/gnome/pixmaps/fpm
	${INSTALL_DATA} ${WRKSRC}/pixmaps/logo.xpm \
	${PREFIX}/share/gnome/pixmaps/fpm
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/fpm
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/fpm
.endfor
.endif
	@${ECHO} "========================================================================="
	@${ECHO} "Make sure you set up a few IRQ's for random generation with rndcontrol before"
	@${ECHO} "expecting password generation to work well."
	@${ECHO} "========================================================================="

.include <bsd.port.mk>
