# New ports collection makefile for:    fidogate
# Date created:         02 Dez 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	fidogate
PORTVERSION=	4.4.3
CATEGORIES=	news mail
MASTER_SITES=	ftp://ftp.fidogate.org/pub/fidogate/ \
		ftp://ftp.fu-berlin.de/unix/news/fidogate/ \
		http://www.fidogate.org/pub/fidogate/
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dirk.meyer@dinoex.sub.org

# you may commet out this line if you have another transfer-agent
RUN_DEPENDS=	${LOCALBASE}/libexec/ifmail/ifcico:${PORTSDIR}/news/ifmail

.if defined(PARALLEL_PACKAGE_BUILD)
FORBIDDEN=	indefinite hang
.endif

USE_GMAKE=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-perl
.endif

pre-configure:
	@${MV} ${WRKSRC}/config.make ${WRKSRC}/config.make.sed
	@${SED} -e 's/\$${PREFIX}/${PREFIX:S/\//\\\//g}/g' \
		< ${WRKSRC}/config.make.sed > ${WRKSRC}/config.make

pre-install:
	${MKDIR} ${PREFIX}/libexec/fidogate
	${MKDIR} ${PREFIX}/share/doc/fidogate/html
	${MKDIR} ${PREFIX}/share/doc/fidogate/info
	${MKDIR} ${PREFIX}/share/doc/fidogate/fido
	${MKDIR} ${PREFIX}/share/doc/fidogate/howto
	${MKDIR} ${PREFIX}/share/doc/fidogate/misc
	${MKDIR} ${PREFIX}/share/doc/fidogate/gatebau

DOCLIST=	\
	fidogate.texi fidogate.txt \
	gatebau94.txt kludge-rfc.doc msgid.doc \
	qmail.txt texinfo.tex \
	dirs.html index.html template.html \
	fido \
	howto \
	misc \
	rfc \
	gatebau/msgid.sgml \
	gatebau/msgid.tex \
	gatebau/msgid.txt

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fidogate
	@cd ${WRKSRC}/doc; tar cf - ${DOCLIST} |\
		(cd ${PREFIX}/share/doc/fidogate; tar xf -)
	${MKDIR} ${PREFIX}/share/examples/fidogate
	@cd ${WRKSRC}/examples; tar cf - . |\
		(cd ${PREFIX}/share/examples/fidogate; tar xf -)
.endif

.include <bsd.port.post.mk>
