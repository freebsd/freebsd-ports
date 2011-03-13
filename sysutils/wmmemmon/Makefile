# New ports collection makefile for:	wmmemmon
# Date created:				Wed May  9 17:55:21 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmmemmon
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mem/Swap monitoring dockapp for WindowMaker

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

#USE_BZIP2=	yes	# ATM the .bz2 distfile is broken.
USE_XORG=	xpm
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

MAN1=		wmmemmon.1
PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/wmmemmon

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700000
EXTRA_PATCHES=	${PATCHDIR}/extra-kvm2sysctl.diff
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^DEFS/s|-I\.\.$$|-I.. -I../libdockapp/|g ; \
		 /^CFLAGS/s|-I../libdockapp/||g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.post.mk>
