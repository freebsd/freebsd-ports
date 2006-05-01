# New ports collection makefile for:	nicetext
# Date created:		20 February 1998
# Whom:			Mark Chapman <markc@ctgi.net>
#
# $FreeBSD$

PORTNAME=	nicetext
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.mirrors.wiretapped.net/security/steganography/nicetext/ \
		http://www.remoteassessment.com/archive/crypt/stego/SourceCode/ \
		http://www.packetstormsecurity.org/crypt/stego/SourceCode/ \
		http://www.theargon.com/achilles/steganography/SourceCode/ \
		http://packetstorm.linuxexposed.com/crypt/stego/SourceCode/ \
		http://sunsite.mff.cuni.cz/MIRRORS/utopia.hacktic.nl/pub/security/steganography/nicetext/ \
		http://archiv.egocrew.de/packet/crypt/stego/SourceCode/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert files to pseudo-natural-language text and back again

USE_GMAKE=	yes
CFLAGS+=	-fpermissive

MAN1=		bitcp.1 dct2mstr.1 expgram.1 genmodel.1 gramtest.1 impkimmo.1 \
		impmsc.1 impwbstr.1 listword.1 nicetext.1 nttpd.1 printint.1 \
		scramble.1 sortdct.1 txt2dct.1
PROGRAMS=	bitcp dct2mstr expgram genmodel gramtest impkimmo impmsc \
		impwbstr listword nicetext nttpd printint rinfo scramble \
		sortdct txt2dct

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
USE_GCC=	3.3
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|gcc|$${CC}|g ; \
		 s|g++|$${CXX}|g'

post-install:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/bin/qstart-nttpd
	@${ECHO_CMD} ${PREFIX}/bin/"nttpd -b " ${EXAMPLESDIR}/database >> ${WRKSRC}/bin/qstart-nttpd
	${CHMOD} a+rx ${WRKSRC}/bin/qstart-nttpd
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qstart-nttpd ${PREFIX}/bin/
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${f} ${PREFIX}/man/man1
.endfor
.for f in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude "*.bak" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREMODE} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples --exclude "*.bak" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREMODE} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
