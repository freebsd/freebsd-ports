# New ports collection makefile for:	textutils
# Date created:		14 May 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $FreeBSD$
#

PORTNAME=	textutils
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	textutils

MAINTAINER=	aw1@stade.co.uk

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gcomm.1 gcsplit.1 gcut.1 gexpand.1 gfmt.1 ghead.1 \
		gjoin.1 gmd5sum.1 gnl.1 gpaste.1 gpr.1 gsort.1 \
		gptx.1 gsum.1 gtac.1 gtail.1 gtr.1 guniq.1 \
		gtsort.1 gwc.1 gcat.1 gcksum.1 gfold.1 god.1 \
		gsplit.1 gunexpand.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

post-install:
	install-info ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include <bsd.port.mk>
