--- src/openvrml/OpenVRML/field.cpp.orig	Wed Oct 16 02:20:24 2002
+++ src/openvrml/OpenVRML/field.cpp	Wed Oct 16 02:25:12 2002
@@ -525,7 +525,7 @@
  *
  * @param rgb a 3-element vector comprising a RGB value
  */
-void SFColor::set(const float rgb[3]) throw () {
+void SFColor::set(const float *rgb) throw () {
     this->d_rgb[0] = rgb[0];
     this->d_rgb[1] = rgb[1];
     this->d_rgb[2] = rgb[2];
@@ -543,7 +543,7 @@
  * @param hsv a 3-element array comprising an HSV value
  * @retval rgb a 3-element array comprising an RGB value
  */
-void SFColor::HSVtoRGB(const float hsv[3], float rgb[3]) throw ()
+void SFColor::HSVtoRGB(const float *hsv, float *rgb) throw ()
 {
     float h = hsv[0];
     if (hsv[1] == 0.0) {
@@ -579,7 +579,7 @@
  * @param rgb a 3-element array comprising an RGB value
  * @retval hsv a 3-element array comprising an HSV value
  */
-void SFColor::RGBtoHSV(const float rgb[3], float hsv[3]) throw () {
+void SFColor::RGBtoHSV(const float *rgb, float *hsv) throw () {
     const float maxrgb = *std::max_element(rgb, rgb + 3);
     const float minrgb = *std::min_element(rgb, rgb + 3);
     
@@ -1320,7 +1320,7 @@
  * @pre The first three elements of <var>rot</var> constitute a normalized
  *      vector.
  */
-void SFRotation::set(const float rot[4]) throw () {
+void SFRotation::set(const float *rot) throw () {
     using OpenVRML_::fpequal;
     using OpenVRML_::length;
     
@@ -1789,7 +1789,7 @@
  *
  * @param vec a 2-element array.
  */
-void SFVec2f::set(const float vec[2]) throw () {
+void SFVec2f::set(const float *vec) throw () {
     this->d_x[0] = vec[0];
     this->d_x[1] = vec[1];
 }
@@ -1920,7 +1920,7 @@
  *
  * @param vec a 3-element array
  */
-SFVec3f::SFVec3f(const float vec[3]) throw () {
+SFVec3f::SFVec3f(const float *vec) throw () {
     std::copy(vec, vec + 3, this->d_x);
 }
 
@@ -2063,7 +2063,7 @@
  *
  * @param vec   a 3-element array
  */
-void SFVec3f::set(const float vec[3]) throw () {
+void SFVec3f::set(const float *vec) throw () {
     this->d_x[0] = vec[0];
     this->d_x[1] = vec[1];
     this->d_x[2] = vec[2];
@@ -2348,7 +2348,7 @@
  * @param index the index of the element to set
  * @param value a 3-element float array comprising the new color value
  */
-void MFColor::setElement(size_t index, const float value[3]) throw () {
+void MFColor::setElement(size_t index, const float *value) throw () {
     assert(index < this->getLength());
     std::copy(value, value + 3, this->d_data->d_v + (index * 3));
 }
@@ -2396,7 +2396,7 @@
  *
  * @exception std::bad_alloc    if memory allocation fails.
  */
-void MFColor::insertElement(const size_t index, const float value[3])
+void MFColor::insertElement(const size_t index, const float *value)
         throw (std::bad_alloc) {
     using std::copy;
     FData * const newData = new FData(this->d_data->d_n + 3);
@@ -3326,7 +3326,7 @@
  * @param index
  * @param value
  */
-void MFRotation::setElement(size_t index, const float value[4]) throw () {
+void MFRotation::setElement(size_t index, const float *value) throw () {
     assert(index * 4 < this->d_data->d_n);
     std::copy(value, value + 4, this->d_data->d_v + (index * 4));
 }
@@ -3376,7 +3376,7 @@
  *
  * @exception std::bad_alloc    if memory allocation fails.
  */
-void MFRotation::insertElement(size_t index, const float value[4])
+void MFRotation::insertElement(size_t index, const float *value)
         throw (std::bad_alloc) {
   FData* newData;
 
@@ -4006,7 +4006,7 @@
  * @param index
  * @param value
  */
-void MFVec2f::setElement(size_t index, const float value[2]) throw () {
+void MFVec2f::setElement(size_t index, const float *value) throw () {
     assert((index * 2) < this->d_data->d_n);
     std::copy(value, value + 2, this->d_data->d_v + (index * 2));
 }
@@ -4050,7 +4050,7 @@
  *
  * @exception std::bad_alloc    if memory allocation fails.
  */
-void MFVec2f::insertElement(size_t index, const float data[2])
+void MFVec2f::insertElement(size_t index, const float *data)
         throw (std::bad_alloc) {
   FData* newData;
 
@@ -4253,7 +4253,7 @@
  * @param index
  * @param value
  */
-void MFVec3f::setElement(size_t index, const float value[3]) throw () {
+void MFVec3f::setElement(size_t index, const float *value) throw () {
     assert((index * 3) < this->d_data->d_n);
     std::copy(value, value + 3, this->d_data->d_v + (index * 3));
 }
@@ -4297,7 +4297,7 @@
  *
  * @exception std::bad_alloc    if memory allocation fails.
  */
-void MFVec3f::insertElement(size_t index, const float value[3])
+void MFVec3f::insertElement(size_t index, const float *value)
         throw (std::bad_alloc) {
   FData* newData;
 
