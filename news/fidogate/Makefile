# New ports collection makefile for:    fidogate
# Version required:     fidogate-4.4.0
# Date created:         02 Dez 1997
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

DISTNAME=	fidogate-4.4.0
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.fido.de/pub/fidogate/ \
		ftp://ftp.gwdg.de/pub/linux/fido/fidogate/ \
		ftp://ftp.fu-berlin.de/unix/news/fidogate/
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dirk.meyer@dinoex.sub.org

# you may commet out this line if you have another transfer-agent
RUN_DEPENDS=	${LOCALBASE}/libexec/ifmail/ifcico:${PORTSDIR}/news/ifmail

.if defined(PARALLEL_PACKAGE_BUILD)
FORBIDDEN=	indefinite hang
.endif

USE_GMAKE=	yes
USE_PERL5=	yes

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

DOCLIST = \
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

.include <bsd.port.mk>
