# New ports collection makefile for:	OpenSP
# Date created:		Jan 6, 2003
# Whom:			kuriyama
#
# $FreeBSD$
#

PORTNAME=	OpenSP
PORTVERSION=	1.5
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openjade

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	This package is a collection of SGML/XML tools called OpenSP

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_GMAKE=	YES
USE_REINPLACE=	YES
USE_LIBTOOL=	YES
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog \
		--datadir=${PREFIX}/share/sgml/openjade
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

INSTALLS_SHLIB=	yes

MAN1=		onsgmls.1 osgmlnorm.1 ospam.1 ospent.1 osx.1
DOC_FILES=	archform.htm autoconf.htm build.htm catalog.htm charset.htm \
		features.htm generic.htm ideas.htm index.htm new.htm \
		nsgmls.htm sgmldecl.htm sgmlnorm.htm sgmlsout.htm spam.htm \
		spcat.htm spent.htm sx.htm sysdecl.htm sysid.htm xml.htm \
		xmlwarn.htm
DOC_FILES2=	NEWS AUTHORS README \
		releasenotes.html releasenotes.pdf releasenotes.ps

# Perhaps this better should be somewhere under ${PREFIX}/share/doc ?
DOCSDIR2=	${PREFIX}/share/sgml/openjade/doc/OpenSP

.include <bsd.port.pre.mk>

# This port cannot be CFLAGS safe, using optimizations such as
# 'march=-mpentium -Os' produces core dumps with certain input files
# Therefore, we'd better remove all machine optimizations and any -O
# other than -O{0,1,}. Idea taken from palm/prc-tools-gcc.
CPPFLAGS:=	-O ${CFLAGS:N-O*:N-m*}

pre-install:
	@${REINPLACE_CMD} -e \
		's|install-man install-pkgdocDATA|install-man|g' \
		${WRKSRC}/Makefile

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor

	@${MKDIR} ${DOCSDIR2}
.for doc in ${DOC_FILES2}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR2}
.endfor

.endif

.include <bsd.port.post.mk>
