diff --git a/libfreerdp-core/orders.c b/libfreerdp-core/orders.c
index 1ee0b89..6c33805 100644
--- libfreerdp-core/orders.c
+++ libfreerdp-core/orders.c
@@ -138,7 +138,7 @@ static const uint8 BMF_BPP[] =
 		0, 1, 0, 8, 16, 24, 32
 };
 
-INLINE void update_read_coord(STREAM* s, sint32* coord, boolean delta)
+static INLINE void update_read_coord(STREAM* s, sint32* coord, boolean delta)
 {
 	sint8 lsi8;
 	sint16 lsi16;
@@ -155,7 +155,7 @@ INLINE void update_read_coord(STREAM* s, sint32* coord, boolean delta)
 	}
 }
 
-INLINE void update_read_color(STREAM* s, uint32* color)
+static INLINE void update_read_color(STREAM* s, uint32* color)
 {
 	uint8 byte;
 
@@ -167,7 +167,7 @@ INLINE void update_read_color(STREAM* s, uint32* color)
 	*color |= (byte << 16);
 }
 
-INLINE void update_read_colorref(STREAM* s, uint32* color)
+static INLINE void update_read_colorref(STREAM* s, uint32* color)
 {
 	uint8 byte;
 
@@ -180,7 +180,7 @@ INLINE void update_read_colorref(STREAM* s, uint32* color)
 	stream_seek_uint8(s);
 }
 
-INLINE void update_read_color_quad(STREAM* s, uint32* color)
+static INLINE void update_read_color_quad(STREAM* s, uint32* color)
 {
 	uint8 byte;
 
@@ -193,7 +193,7 @@ INLINE void update_read_color_quad(STREAM* s, uint32* color)
 	stream_seek_uint8(s);
 }
 
-INLINE void update_read_2byte_unsigned(STREAM* s, uint32* value)
+static INLINE void update_read_2byte_unsigned(STREAM* s, uint32* value)
 {
 	uint8 byte;
 
@@ -211,7 +211,7 @@ INLINE void update_read_2byte_unsigned(STREAM* s, uint32* value)
 	}
 }
 
-INLINE void update_read_2byte_signed(STREAM* s, sint32* value)
+static INLINE void update_read_2byte_signed(STREAM* s, sint32* value)
 {
 	uint8 byte;
 	boolean negative;
@@ -232,7 +232,7 @@ INLINE void update_read_2byte_signed(STREAM* s, sint32* value)
 		*value *= -1;
 }
 
-INLINE void update_read_4byte_unsigned(STREAM* s, uint32* value)
+static INLINE void update_read_4byte_unsigned(STREAM* s, uint32* value)
 {
 	uint8 byte;
 	uint8 count;
@@ -276,7 +276,7 @@ INLINE void update_read_4byte_unsigned(STREAM* s, uint32* value)
 	}
 }
 
-INLINE void update_read_delta(STREAM* s, sint32* value)
+static INLINE void update_read_delta(STREAM* s, sint32* value)
 {
 	uint8 byte;
 
@@ -294,7 +294,7 @@ INLINE void update_read_delta(STREAM* s, sint32* value)
 	}
 }
 
-INLINE void update_read_glyph_delta(STREAM* s, uint16* value)
+static INLINE void update_read_glyph_delta(STREAM* s, uint16* value)
 {
 	uint8 byte;
 
@@ -306,7 +306,7 @@ INLINE void update_read_glyph_delta(STREAM* s, uint16* value)
 		*value = (byte & 0x3F);
 }
 
-INLINE void update_seek_glyph_delta(STREAM* s)
+static INLINE void update_seek_glyph_delta(STREAM* s)
 {
 	uint8 byte;
 
@@ -316,7 +316,7 @@ INLINE void update_seek_glyph_delta(STREAM* s)
 		stream_seek_uint8(s);
 }
 
-INLINE void update_read_brush(STREAM* s, rdpBrush* brush, uint8 fieldFlags)
+static INLINE void update_read_brush(STREAM* s, rdpBrush* brush, uint8 fieldFlags)
 {
 	if (fieldFlags & ORDER_FIELD_01)
 		stream_read_uint8(s, brush->x);
@@ -354,7 +354,7 @@ INLINE void update_read_brush(STREAM* s, rdpBrush* brush, uint8 fieldFlags)
 	}
 }
 
-INLINE void update_read_delta_rects(STREAM* s, DELTA_RECT* rectangles, int number)
+static INLINE void update_read_delta_rects(STREAM* s, DELTA_RECT* rectangles, int number)
 {
 	int i;
 	uint8 flags = 0;
@@ -399,7 +399,7 @@ INLINE void update_read_delta_rects(STREAM* s, DELTA_RECT* rectangles, int numbe
 	}
 }
 
-INLINE void update_read_delta_points(STREAM* s, DELTA_POINT* points, int number, sint16 x, sint16 y)
+static INLINE void update_read_delta_points(STREAM* s, DELTA_POINT* points, int number, sint16 x, sint16 y)
 {
 	int i;
 	uint8 flags = 0;
