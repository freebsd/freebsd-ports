# New ports collection makefile for:   muttprint
# Date created:        11 november 2001
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	muttprint
PORTVERSION=	0.63a
PORTCOMMENT=	Utility to print mail for most any mail client
CATEGORIES=	print mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	muttprint

MAINTAINER=	obraun@FreeBSD.org

.if !defined(PAPERSIZE)
PAPERSIZE=	letter
.endif

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		psnup:${PORTSDIR}/print/psutils-${PAPERSIZE} \
		uncompface:${PORTSDIR}/mail/faces \
		convert:${PORTSDIR}/graphics/ImageMagick \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_GMAKE=	yes
ALL_TARGET=	nothing

MAN1=		muttprint.1
MANCOMPRESSED=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET=install-with-doc
.endif

post-patch:
	@${RM} -f ${WRKSRC}/pics/*.orig
	@${GUNZIP_CMD} ${WRKSRC}/doc/manpages/*/muttprint.1.gz
	@${REINPLACE_CMD} -e 's|/usr/share/doc/packages|${PREFIX}/share/doc|g ; \
		s|/usr/share|${PREFIX}/share|g ; \
		s|/usr/bin|${PREFIX}/bin|g ; \
		s|/etc|${PREFIX}/etc|g ; \
		s|/usr/lib|${PREFIX}/lib|g' \
			${WRKSRC}/doc/manpages/*/muttprint.1 \
			${WRKSRC}/doc/manual/*/manual-*/*.html
	@${GZIP_CMD} ${WRKSRC}/doc/manpages/*/muttprint.1

.include <bsd.port.mk>
