# New ports collection makefile for:	enscript
# Version required:     	1.5.0
# Date created:			24 Jul, 1997
# Whom:				kline
#
# $Id: Makefile,v 1.3 1997/11/10 11:23:19 asami Exp $
#

DISTNAME=       enscript-1.5.0
PKGNAME=        enscript-${PAPERSIZE}-1.5.0
CATEGORIES=	print
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	kline@thought.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to Letter A4
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-nls --with-media=${PAPERSIZE}
MAKE_FLAGS=     WIDTH=${WIDTH} HEIGHT=${HEIGHT} A4_PAPERSIZE=${A4_PAPERSIZE} -f

MAN1=		enscript.1 sliceprint.1 states.1
STRIP=

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

.if !defined(PAPERSIZE)
PAPERSIZE=A4     # set default
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
PAPERSIZE_UNSPECIFIED=  yes
.elif ${PAPERSIZE} == A4 || ${PAPERSIZE} == a4
PAPERSIZE=A4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
.elif ${PAPERSIZE} == letter || ${PAPERSIZE} == LETTER || ${PAPERSIZE} == Letter
PAPERSIZE=Letter
WIDTH=8.5
HEIGHT=11.0
A4_PAPERSIZE=0
.elif ${PAPERSIZE} == Letterdj
.else
PAPERSIZE_INVALID= yes
.endif  # not defined PAPERSIZE

pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@echo ""
	@echo "This port builds the default A4 paper size."
	@echo "If you want to select the LETTER papersize for enscript,"
	@echo "type a ^C now.  Then type:"
	@echo ""
	@echo "  % make letter "
	@echo ""
	@echo "Install your port by typing:"
	@echo ""
	@echo "make letter-install  {or} % make a4-install"
	@echo ""
	@echo "You can also set the environment variable PAPERSIZE to A4 or"
	@echo "letter to configure enscript for these paper sizes"
	@sleep 5
.elif defined(PAPERSIZE_INVALID)
	@echo "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@echo "Possible values are:  A4 (default) or letter"
	@${FALSE}
.endif
letter::
	${MAKE} PAPERSIZE=Letter

Letter::
	${MAKE} PAPERSIZE=Letter

letter-install::
	${MAKE} PAPERSIZE=Letter install

Letter-install::
	${MAKE} PAPERSIZE=Letter install

a4::
	${MAKE} PAPERSIZE=A4

A4::
	${MAKE} PAPERSIZE=A4

Letterdj::
	${MAKE} PAPERSIZE=Letterdj

letterdj::
	${MAKE} PAPERSIZE=Letterdj

Letterdj-install::
	${MAKE} PAPERSIZE=Letterdj install

letterdj-install::
	${MAKE} PAPERSIZE=Letterdj install

a4-install::
	${MAKE} PAPERSIZE=a4 install

A4-install::
	${MAKE} PAPERSIZE=a4 install

post-install:
.for file in enscript mkafmmap states
	strip ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
