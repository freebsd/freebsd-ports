--- share/mk/doc.docbook.mk.orig	2018-04-02 17:55:35 UTC
+++ share/mk/doc.docbook.mk
@@ -234,7 +234,7 @@ CLEANFILES+= ${DOC}.aux ${DOC}.dvi ${DOC}.log ${DOC}.o
 .if ${RENDERENGINE} == "fop"
 XSLTPROCOPTS+=	--param img.src.path "'${IMGDIR}/'"
 XSLTPROCOPTS+=	--param callout.graphics.path "'${CALLOUTDIR}/'"
-XSLTPROCOPTS+=	--maxdepth 6000
+XSLTPROCOPTS+=	--maxdepth 12000
 .endif
 .for _curimage in ${LOCAL_IMAGES_EPS:M*share*}
 CLEANFILES+= ${_curimage:T} ${_curimage:H:T}/${_curimage:T}
