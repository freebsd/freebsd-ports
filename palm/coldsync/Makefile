# New ports collection makefile for:	coldsync
# Date created:		27 January 2000
# Whom:			Andrew Arensburger <arensb+freebsd-ports@ooblick.com>
#
# $FreeBSD$
#

PORTNAME=	coldsync
PORTVERSION=	2.1.3
PORTREVISION=	3
CATEGORIES=	palm comms
MASTER_SITES=	http://www.coldsync.org/download/

MAINTAINER=	arensb+freebsd-ports@ooblick.com

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Palm/PDB.pm:${PORTSDIR}/palm/p5-Palm
USE_PERL=	yes

GNU_CONFIGURE=	yes

# The ColdSync.3 man page describes a Perl package. That's why it goes
# in the Perl manpage directory.
MAN1=		send-mail.1 \
		todo-text.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		ColdSync.3 \
		ColdSync::SPC.3
MAN8=		coldsync.8
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

CFLAGS+=	-D__BSD_VISIBLE=1
CONFIGURE_ARGS+=	--with-i18n --disable-pedantic

# I don't know how to test for a version of {Net,Open}BSD that supports USB.
.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 400000
CONFIGURE_ARGS+=	--with-usb
.if ${OSVERSION} >= 450000
post-patch:
	${PERL} -pi -e 's,udi\.(\S+),udi.udi_\1,g;' \
		-e 's,ur\.(\S+),ur.ucr_\1,g;' \
		${WRKSRC}/configure ${WRKSRC}/libpconn/PConnection_usb.c
.endif
.endif

post-install:
	@install-info ${PREFIX}/info/conduits.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>
