# ex:ts=8
# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME?=	nmap
PORTVERSION=	2.54.b34
CATEGORIES=	security
MASTER_SITES=	http://www.insecure.org/nmap/dist/  \
		ftp://nuxi.ucdavis.edu/pub/misc/  \
		http://www.mobis.com/ajax/projects/
DISTNAME=	nmap-${PORTVERSION:S/.b/BETA/}
EXTRACT_SUFX=	.tgz
PLIST=	pkg-plist
MAINTAINER=	dominic_marks@btinternet.com

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
.if ${OSVERSION} < 300004
CFLAGS+=	-DDLT_RAW=12 # for obsoleted <net/bpf.h>
.endif
MAN1?=		nmap.1

pre-configure:
.if !defined (HAVE_GTK)
	@${SED} -e "s,) nmapfe/nmapfe,),g" \
		${WRKSRC}/Makefile.in > ${WRKDIR}/Makefile.in.temp
	@${MV} ${WRKDIR}/Makefile.in.temp ${WRKSRC}/Makefile.in
.else
	@${SED} -e "s,gtk-config,gtk12-config,g" \
		${WRKSRC}/nmapfe/configure > ${WRKDIR}/configure.temp
	@${MV} ${WRKDIR}/configure.temp ${WRKSRC}/nmapfe/configure
.endif

.if !target(post-install) && (${PORTNAME} == "nmap")
post-install:
	@strip ${PREFIX}/bin/nmap
.if defined (HAVE_GTK)
	cd ${WRKSRC} && ${MAKE} install-nmapfe
	echo "bin/nmapfe" >> ${PLIST}
.endif
.endif

.include <bsd.port.post.mk>
